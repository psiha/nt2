//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_$MODULE_NAME$_FUNCTIONS_$NAME$_HPP_INCLUDED
#define NT2_TOOLBOX_$MODULE_NAME$_FUNCTIONS_$NAME$_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

/*!
 * \ingroup $module_name$
 * \defgroup $module_name$_$name$ $name$
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library $module_name$.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/toolbox/$module_name$/include/functions/$name$.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace $module_name$
 *   {
 *     template <$class_types$>
 *       meta::call<tag::$name$_($simple_types_call$)>::type
 *       $name$($constref_full_typed_params$);
 *   }
 * }
 * \endcode
 *
 * \return a value of the same type as the first parameter
 *  
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 * When calling external library, nt2 simply encapsulates the
 * original proper call to provide easy use.
 * \par
 * Remenber that SIMD implementation is therefore merely
 * mapping the scalar function to each SIMD vectors elements
 * and will not provide acceleration, but ease.
 * \par
 * $module_name$ library defines functions for double entries (A0) only,
 * A1 being int entries.
 * Nevertheless, they can be called with float A0 entries under nt2 calls
 * to return float outputs.
 *  
**/

namespace nt2 { namespace $module_name$ { namespace tag
  {         
    /*!
     * \brief Define the tag $name$_ of functor $name$ 
     *        in namespace nt2::$module_name$::tag for toolbox $module_name$
    **/
    struct $name$_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION($module_name$::tag::$name$_, $name$, $param_number$)
  } }

#include <nt2/toolbox/$module_name$/functions/scalar/$name$.hpp>

#endif

// created by jt the 12/6/2011
