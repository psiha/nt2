//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012 - 2013 MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_IEEE_FUNCTIONS_GENERIC_SATURATE_HPP_INCLUDED
#define BOOST_SIMD_IEEE_FUNCTIONS_GENERIC_SATURATE_HPP_INCLUDED

#include <boost/simd/ieee/functions/saturate.hpp>
#include <boost/simd/include/functions/simd/splat.hpp>
#include <boost/simd/include/functions/simd/min.hpp>
#include <boost/simd/include/functions/simd/max.hpp>
#include <boost/simd/include/constants/valmax.hpp>
#include <boost/simd/include/constants/valmin.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/sdk/meta/scalar_of.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/sizeof.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_IF( boost::simd::tag::saturate_, tag::cpu_
                                      , (A0)(T)
                                      , (is_same<typename meta::scalar_of<typename T::type>::type, typename meta::scalar_of<A0>::type>)
                                      , (generic_< arithmetic_<A0> >)
                                        (target_< generic_<arithmetic_<T> > >)
                                      )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0, T const& ) const
    {
      return a0;
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::saturate_, tag::cpu_
                                    , (A0)(T)
                                    , (generic_< signed_<A0> >)
                                      (target_< generic_< arithmetic_<T> > >)
                                    )
  {
    typedef A0 result_type;
    typedef typename meta::scalar_of<T>::type target_t;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0, T const& ) const
    {
      const A0 vma = splat<A0>(Valmax<target_t>());
      const A0 vmi = splat<A0>(Valmin<target_t>());
      return min(vma, max(vmi, a0));
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION ( boost::simd::tag::saturate_, tag::cpu_
                                    , (A0)(T)
                                    , (generic_<unsigned_<A0> >)
                                      (target_< generic_< arithmetic_<T> > >)
                                    )
  {
    typedef A0 result_type;
    typedef typename meta::scalar_of<T>::type target_t;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0, T const& ) const
    {
      const A0 vma = splat<A0>(Valmax<target_t>());
      return min(vma, a0);
    }
  };

  BOOST_SIMD_FUNCTOR_IMPLEMENTATION_IF( boost::simd::tag::saturate_, tag::cpu_
                                      , (A0)(T)
                                      , (mpl::equal_to< mpl::sizeof_<typename meta::scalar_of<typename T::type>::type>, mpl::sizeof_<typename meta::scalar_of<A0>::type> >)
                                      , (generic_< int_<A0> >)
                                        (target_< generic_< uint_<T> > >)
                                      )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& a0, T const& ) const
    {
      return max(Zero<A0>(), a0);
    }
  };
} } }

#endif