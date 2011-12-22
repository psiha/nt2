//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_SCALAR_R_POW_DI_HPP_INCLUDED
#define NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_SCALAR_R_POW_DI_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>

namespace r_mathlib
{
  extern "C"{
    extern double R_pow_di ( double,int );
  }
}

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::r_mathlib::tag::R_pow_di_, tag::cpu_
                            , (A0)
                            , ((scalar_<arithmetic_<A0> >)(scalar_<integer_<A1> >))
                            )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      typedef result_type                         base;
      typedef typename meta::upgrade<base>::type  type;
      return static_cast<result_type>(nt2::r_mathlib::R_pow_di(double(a0), int(a1));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION(nt2::r_mathlib::tag::R_pow_di_, tag::cpu_
                            , (A0)(A1)
                            , (scalar_<double_<A0> >)(scalar_<integer_<A1> >)
                            )
  {
    typedef A0 result_type;
    tempate <class A0, class A1> inline result_type
    operator()(A0 const& a0, A1 const& a1) 
    { return ::r_mathlib::R_pow_di(a0, a1); }
  };
} }


#endif
