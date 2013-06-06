//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_PREDICATES_FUNCTIONS_COMPLEX_GENERIC_IS_NOT_IMAG_HPP_INCLUDED
#define NT2_PREDICATES_FUNCTIONS_COMPLEX_GENERIC_IS_NOT_IMAG_HPP_INCLUDED
#include <nt2/predicates/functions/is_not_imag.hpp>
#include <nt2/include/functions/is_eqz.hpp>
#include <nt2/include/constants/false.hpp>
#include <nt2/sdk/complex/complex.hpp>
#include <nt2/sdk/complex/imaginary.hpp>
#include <nt2/sdk/simd/logical.hpp>
#include <nt2/sdk/complex/meta/as_dry.hpp>
#include <nt2/sdk/complex/meta/as_real.hpp>

namespace nt2 { namespace ext
{
  // complex
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::is_not_imag_, tag::cpu_, (A0)
                            , (generic_< complex_< arithmetic_<A0> > >)
                            )
  {
    typedef typename  meta::imag_of<A0>::type rA0;
    typedef typename meta::as_logical<rA0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return is_nez(nt2::real(a0));
    }
  };

  // imaginary
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::is_not_imag_, tag::cpu_, (A0),
                              (generic_< imaginary_< arithmetic_<A0> > > )
                            )
  {
    typedef typename meta::as_real<A0>::type rA0;
    typedef typename meta::as_logical<rA0>::type result_type;
    inline result_type operator()(const A0&) const
    {
      return False<result_type>();
    }
  };
  // dry
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::is_not_imag_, tag::cpu_, (A0)
                            , (generic_< dry_< arithmetic_<A0> > >)
                            )
  {
    typedef typename  meta::imag_of<A0>::type rA0;
    typedef typename meta::as_logical<rA0>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      return is_nez(nt2::real(a0));
    }
  };


} }

#endif