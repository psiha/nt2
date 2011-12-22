//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_SCALAR_R_POW_HPP_INCLUDED
#define NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_SCALAR_R_POW_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>

namespace r_mathlib
{
  extern "C"{
    extern double R_pow ( double,double );
  }
}

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::r_mathlib::tag::R_pow_, tag::cpu_
                            , (A0)
                            , ((scalar_<arithmetic_<A0> >))
                            )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type result_type;
    NT2_FUNCTOR_CALL(1)
    {
      typedef result_type                         base;
      typedef typename meta::upgrade<base>::type  type;
      return static_cast<result_type>(nt2::r_mathlib::R_pow(double(a0), double(a1));
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION(nt2::r_mathlib::tag::R_pow_, tag::cpu_
                            , (A0)
                            , (scalar_<double_<A0> >)
                            )
  {
    typedef A0 result_type;
    tempate <class A0> inline result_type
    operator()(A0 const& a0, A0 const& a1) 
    { return ::r_mathlib::R_pow(a0, a1); }
  };
} }


#endif
