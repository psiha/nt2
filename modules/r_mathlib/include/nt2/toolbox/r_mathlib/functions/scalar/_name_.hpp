//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef NT2_TOOLBOX_$MODULE_NAME$_FUNCTIONS_SCALAR_$NAME$_HPP_INCLUDED
#define NT2_TOOLBOX_$MODULE_NAME$_FUNCTIONS_SCALAR_$NAME$_HPP_INCLUDED
#include <nt2/sdk/meta/upgrade.hpp>

extern "C"{
  extern double $name$ ( $params$ );
}

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION(nt2::$module_name$::tag::$name$_, tag::cpu_
                            , $par_simple_full_list_types$
                            , $scalar_arithmetic_full_types$
                            )
  {
    typedef typename meta::result_of<meta::floating(A0)>::type result_type;
    inline result_type
    operator()($constref_full_params$)  const 
    {
      typedef result_type                         base;
      typedef typename meta::upgrade<base>::type  type;
      return static_cast<result_type>(::$name$($casted_call$));
    }
  };
} }


#endif
