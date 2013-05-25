//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.bitwise toolbox - shr/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.bitwise components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 18/02/2011
///
#include <boost/simd/bitwise/include/functions/shr.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/mone.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/include/constants/two.hpp>
#include <boost/simd/include/constants/three.hpp>

NT2_TEST_CASE_TPL ( shr_unsigned_int__2_0,  BOOST_SIMD_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::shr;
  using boost::simd::tag::shr_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                          ext_t;
  typedef native<T,ext_t>                                          vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type      iT;
  typedef native<iT,ext_t>                                        ivT;
  typedef typename boost::dispatch::meta::call<shr_(vT,iT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(shr(boost::simd::Two<vT>(),1), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),(sizeof(T)*8-1)), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),(sizeof(T)*8-2)), boost::simd::Three<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::One<vT>(),1), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Zero<vT>(),1), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( shr_unsigned_int__2_0_1,  BOOST_SIMD_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using boost::simd::shr;
  using boost::simd::tag::shr_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                          ext_t;
  typedef native<T,ext_t>                                          vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type      iT;
  typedef native<iT,ext_t>                                        ivT;
  typedef typename boost::dispatch::meta::call<shr_(vT,iT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(shr(boost::simd::Two<vT>(),1), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),(sizeof(T)*8-1)), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),(sizeof(T)*8-2)), boost::simd::Three<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::One<vT>(),1), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Zero<vT>(),1), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( shr_unsigned_int__2_1_0,  BOOST_SIMD_SIMD_UNSIGNED_TYPES)
{
  using boost::simd::shr;
  using boost::simd::tag::shr_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                          ext_t;
  typedef native<T,ext_t>                                          vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type      iT;
  typedef native<iT,ext_t>                                        ivT;
  typedef typename boost::dispatch::meta::call<shr_(vT,ivT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(shr(boost::simd::Two<vT>(),boost::simd::One<ivT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),boost::simd::splat<ivT>(sizeof(T)*8-1)), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),boost::simd::splat<ivT>(sizeof(T)*8-2)), boost::simd::Three<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::One<vT>(),boost::simd::One<ivT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Zero<vT>(),boost::simd::One<ivT>()), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( shr_unsigned_int__2_1_1,  BOOST_SIMD_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using boost::simd::shr;
  using boost::simd::tag::shr_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                          ext_t;
  typedef native<T,ext_t>                                          vT;
  typedef typename boost::dispatch::meta::as_integer<T>::type      iT;
  typedef native<iT,ext_t>                                        ivT;
  typedef typename boost::dispatch::meta::call<shr_(vT,ivT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(shr(boost::simd::Two<vT>(),boost::simd::One<ivT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),boost::simd::splat<ivT>(sizeof(T)*8-1)), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Mone<vT>(),boost::simd::splat<ivT>(sizeof(T)*8-2)), boost::simd::Three<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::One<vT>(),boost::simd::One<ivT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(shr(boost::simd::Zero<vT>(),boost::simd::One<ivT>()), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_
