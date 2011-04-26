/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_SIMD_DETAILS_IMPL_COMMON_IS_GREATER_HPP_INCLUDED
#define NT2_SDK_SIMD_DETAILS_IMPL_COMMON_IS_GREATER_HPP_INCLUDED

#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/genmask.hpp>

NT2_REGISTER_DISPATCH ( tag::is_greater_, tag::cpu_, (X)(A0)(A1)
                      , ((simd_<fundamental_<A0>, X>))((simd_<fundamental_<A1>, X>))
                      )
namespace nt2 { namespace ext
{
  template<class X,class Dummy>
  struct call<tag::is_greater_(tag::simd_<tag::fundamental_,X>, tag::simd_<tag::fundamental_,X>), tag::cpu_, Dummy>
        : callable
  {
    template<class Sig> struct result;
    template<class This,class A>
    struct result<This(A,A)> : meta::strip<A> {};

    NT2_FUNCTOR_CALL(2)
    {
      A0 that = map ( functor<tag::genmask_>()
                    , map(functor<tag::is_greater_>(), a0, a1)
                    );
      return that;
    }
  };
} }

#endif
