//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/toolbox/ieee/include/functions/fast_frexp.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/half.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/fusion/include/vector_tie.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

NT2_TEST_CASE_TPL( fast_frexp,  NT2_REAL_TYPES)
{
  using boost::simd::fast_frexp;
  using boost::simd::tag::fast_frexp_;

  typedef typename boost::dispatch::meta::as_integer<T,signed>::type iT;

  NT2_TEST_TYPE_IS( (typename boost::dispatch::meta::call<fast_frexp_(T)>::type)
                  , (std::pair<T,iT>)
                  );

  {
    iT e;
    T  m;

    fast_frexp(boost::simd::One<T>(), m, e);
    NT2_TEST_EQUAL(m, boost::simd::Half<T>());
    NT2_TEST_EQUAL(e, boost::simd::One<T>());
  }

  {
    iT e;
    T  m;

    m = fast_frexp(boost::simd::One<T>(), e);
    NT2_TEST_EQUAL(m, boost::simd::Half<T>());
    NT2_TEST_EQUAL(e, boost::simd::One<T>());
  }

  {
    iT e;
    T  m;

    boost::fusion::vector_tie(m,e) = fast_frexp(boost::simd::One<T>());
    NT2_TEST_EQUAL(m, boost::simd::Half<T>());
    NT2_TEST_EQUAL(e, boost::simd::One<T>());
  }

  {
    std::pair<T,iT> p;

    p = fast_frexp(boost::simd::One<T>());
    NT2_TEST_EQUAL(p.first  , boost::simd::Half<T>());
    NT2_TEST_EQUAL(p.second , boost::simd::One<T>());
  }
}
