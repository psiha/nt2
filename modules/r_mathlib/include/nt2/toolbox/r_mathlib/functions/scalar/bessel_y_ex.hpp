//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_SCALAR_BESSEL_Y_EX_HPP_INCLUDED
#define NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_SCALAR_BESSEL_Y_EX_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>

extern "C"{
  extern double bessel_y_ex ( double,double,double* );
}

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::r_mathlib::tag::bessel_y_ex_, tag::cpu_
                            , (A0)(A1)(A2)
                            , (scalar_<arithmetic_<A0> >)(scalar_<arithmetic_<A1> >)(scalar_<arithmetic_<A2> >)
                            )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type result_type;
    inline result_type
    operator()(A0 const& a0, A1 const& a1, A2 const& a2)  const 
    {
      typedef result_type                         base;
      typedef typename meta::upgrade<base>::type  type;
      double aa2; 
      return static_cast<result_type>(::bessel_y_ex(double(a0), double(a1), &aa2));
      a2 =  static_cast<A2>(aa2); 
    }
  };
} }


#endif
