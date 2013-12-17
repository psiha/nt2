//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2013   MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

#include <nt2/sdk/bench/benchmark.hpp>
#include <fstream>
#include <boost/simd/sdk/simd/pack.hpp>
#include <boost/simd/include/functions/aligned_load.hpp>
#include  <boost/simd/operator/functions/multiplies.hpp>
#include <boost/simd/arithmetic/functions/muls.hpp>
#include <boost/simd/include/functions/plus.hpp>
#include <boost/simd/include/functions/sum.hpp>
#include <boost/simd/include/functions/aligned_store.hpp>
#include <boost/simd/memory/allocator.hpp>

using namespace nt2;
template<typename T>
NT2_EXPERIMENT(rgb2yuv)
{
  public :
    rgb2yuv(int h, int w)
    : NT2_EXPERIMENT_CTOR(1,"cycles/elements"), height(h), width(w), size(h*w)
  {
    y.resize(size);
    u.resize(size);
    v.resize(size);
    r.resize(size);
    g.resize(size);
    b.resize(size);
    for(int i=0; i<size; i++)
      r[i] = g[i] = b[i] = y[i] = u[i] = v[i] = T(i);
  }

  virtual void info(std::ostream& os) const { os <<size; }

  BOOST_FORCEINLINE virtual void run() const
  {
    using boost::simd::pack;
    using boost::simd::aligned_load;
    using boost::simd::aligned_store;
    using boost::simd::sum;

    typedef pack<T> type;
    type tmp_y;
    std::size_t i=0;
    step_size_=boost::simd::meta::cardinal_of<type>::value;

    while (size-i>=step_size_)
    {
      type x1 = aligned_load< type >(&r[i]);
      type x2 = aligned_load< type >(&g[i]);
      type x3 = aligned_load< type >(&b[i]);

      tmp_y = T(0.299f)*x1 + T(0.587f)*x2 + T(0.114f)*x3;

      aligned_store(tmp_y, &y[i]);
      aligned_store(T(0.492f)*(x3 - tmp_y), &u[i]);
      aligned_store(T(0.877f)*(x1 - tmp_y), &v[i]);
      i += step_size_;
    }
    for (;i<size;i++)
    {
      y[i]=0.299f*r[i] + 0.587f*g[i] + 0.114f*b[i];
      u[i]=0.492f*(b[i]-y[i]);
      v[i]=0.877f*(r[i]-y[i]);
    }
  }

  virtual double compute(nt2::benchmark_result_t const& r) const
  {
    return r.first/double(size);
  }

  virtual void reset()
  {
  }

  private:
    int height;
    int width;
    int size;
    std::vector<T,boost::simd::allocator<T> > r;
    std::vector<T,boost::simd::allocator<T> > g;
    std::vector<T,boost::simd::allocator<T> > b;
    mutable std::size_t step_size_;
    mutable std::vector<T,boost::simd::allocator<T> > y;
    mutable std::vector<T,boost::simd::allocator<T> > u;
    mutable std::vector<T,boost::simd::allocator<T> > v;
};

NT2_RUN_EXPERIMENT_TPL(rgb2yuv,(float)(double),(100,100));
NT2_RUN_EXPERIMENT_TPL(rgb2yuv,(float)(double),(50,50));
NT2_RUN_EXPERIMENT_TPL(rgb2yuv,(float)(double),(1000,500));
NT2_RUN_EXPERIMENT_TPL(rgb2yuv,(float)(double),(312,43));
