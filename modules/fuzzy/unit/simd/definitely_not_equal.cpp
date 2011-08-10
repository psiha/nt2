//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 fuzzy toolbox - definitely_not_equal/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of fuzzy components in simd mode
//////////////////////////////////////////////////////////////////////////////
/// created  by jt the 04/03/2011
/// 
#include <nt2/toolbox/fuzzy/include/definitely_not_equal.hpp>
#include <nt2/include/functions/ulpdist.hpp>
#include <nt2/sdk/meta/logical.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_real.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <nt2/sdk/meta/floating.hpp>
#include <nt2/sdk/meta/arithmetic.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/include/constants/real.hpp>
#include <nt2/sdk/meta/cardinal_of.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/sdk/memory/is_aligned.hpp>
#include <nt2/sdk/memory/aligned_type.hpp>
#include <nt2/include/functions/load.hpp>


NT2_TEST_CASE_TPL ( definitely_not_equal_real__3_0,  NT2_SIMD_REAL_TYPES)
{
  using nt2::definitely_not_equal;
  using nt2::tag::definitely_not_equal_;
  using nt2::load; 
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<definitely_not_equal_(vT,vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<definitely_not_equal_(T,T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(definitely_not_equal(nt2::splat<vT>(0),nt2::splat<vT>(0),nt2::splat<ivT>(1))[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(definitely_not_equal(nt2::splat<vT>(0),nt2::splat<vT>(1),nt2::splat<ivT>(1))[0]!=0, nt2::True<sr_t>());
} // end of test for real_

NT2_TEST_CASE_TPL ( definitely_not_equal_signed_int__3_0,  NT2_SIMD_INTEGRAL_SIGNED_TYPES)
{
  using nt2::definitely_not_equal;
  using nt2::tag::definitely_not_equal_;
  using nt2::load; 
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<definitely_not_equal_(vT,vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<definitely_not_equal_(T,T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(definitely_not_equal(nt2::splat<vT>(0),nt2::splat<vT>(0),nt2::splat<ivT>(1))[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(definitely_not_equal(nt2::splat<vT>(0),nt2::splat<vT>(1),nt2::splat<ivT>(1))[0]!=0, nt2::False<sr_t>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( definitely_not_equal_unsigned_int__3_0,  NT2_SIMD_UNSIGNED_TYPES)
{
  using nt2::definitely_not_equal;
  using nt2::tag::definitely_not_equal_;
  using nt2::load; 
  using boost::simd::native;
  using nt2::meta::cardinal_of;
  typedef NT2_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef typename nt2::meta::upgrade<T>::type   u_t;
  typedef native<T,ext_t>                        n_t;
  typedef n_t                                     vT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef native<iT,ext_t>                       ivT;
  typedef typename nt2::meta::call<definitely_not_equal_(vT,vT,ivT)>::type r_t;
  typedef typename nt2::meta::call<definitely_not_equal_(T,T,iT)>::type sr_t;
  typedef typename nt2::meta::scalar_of<r_t>::type ssr_t;
  double ulpd;
  ulpd=0.0;


  // specific values tests
  NT2_TEST_EQUAL(definitely_not_equal(nt2::splat<vT>(0),nt2::splat<vT>(0),nt2::splat<ivT>(1))[0]!=0, nt2::False<sr_t>());
  NT2_TEST_EQUAL(definitely_not_equal(nt2::splat<vT>(0),nt2::splat<vT>(1),nt2::splat<ivT>(1))[0]!=0, nt2::False<sr_t>());
} // end of test for unsigned_int_
