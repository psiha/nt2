//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BESSEL_FUNCTION_SCALAR_Y0_HPP_INCLUDED
#define NT2_TOOLBOX_BESSEL_FUNCTION_SCALAR_Y0_HPP_INCLUDED
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/constant/real.hpp>

#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/oneminus.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/log.hpp>
#include <nt2/include/functions/j0.hpp>
#include <nt2/include/functions/rec.hpp>
#include <nt2/include/functions/sin.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for y0

  /////////////////////////////////////////////////////////////////////////////
  // Compute y0(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is float
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<y0_,tag::scalar_(tag::arithmetic_),float,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename meta::scalar_of<A0>::type stype; 
      if (a0 < 0) return Nan<A0>();
      if (a0 <= Two<A0>())
	{
	  A0 z = sqr(a0); 
	  A0 p2 = (z-single_constant<A0, 0x3edd4b3a>())*
	    horner< NT2_HORNER_COEFF_T(stype, 5,
				    (0x33cb0920, 
				     0xb71ded71, 
				     0x3a0c1a3e, 
				     0xbc81c8f4, 
				     0x3e2edb4f
				     ) ) > (z);
	     return p2+single_constant<A0, 0x3f22f983>()*nt2::log(a0)*nt2::j0(a0);
	}
	 A0 q = rec(a0);
	 A0 w = sqrt(q); 
	 A0 p3 = w *
	   horner< NT2_HORNER_COEFF_T(stype, 8,
				    (0xbd8c100e, 
				     0x3e3ef887, 
				     0xbe5ba616, 
				     0x3df54214, 
				     0xbb69539e, 
				     0xbd4b8bc1, 
				     0xb6612dc2, 
				     0x3f4c422a
				     ) ) > (q);
         w = sqr(q);
         A0 xn =  q*
	   horner< NT2_HORNER_COEFF_T(stype, 8,
				    (0x4201aee0, 
				     0xc2113945, 
				     0x418c7f6a, 
				     0xc09f3306, 
				     0x3f8040aa, 
				     0xbe46a57f, 
				     0x3d84ed6e, 
				     0xbdffff97
				     ) ) > (w)-Pio_4<A0>();
         return p3*nt2::sin(xn+a0); 
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is double
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<y0_,tag::scalar_(tag::arithmetic_),double,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
        return ::y0(a0); 
    }
  };


  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type A0 is arithmetic_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<y0_,tag::scalar_(tag::arithmetic_),arithmetic_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL(1)
    {
      typedef typename NT2_CALL_RETURN_TYPE(1)::type type; 
      return nt2::y0(type(a0)); 
    }
  };

} }

#endif
/// Revised by jt the 15/11/2010
