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
#ifndef NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_PLNORM_HPP_INCLUDED
#define NT2_TOOLBOX_R_MATHLIB_FUNCTIONS_PLNORM_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>

/*!
 * \ingroup r_mathlib
 * \defgroup r_mathlib_plnorm plnorm
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library r_mathlib.
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/toolbox/r_mathlib/include/functions/plnorm.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace r_mathlib
 *   {
 *     template <class A0, class A1>
 *       meta::call<tag::plnorm_(A0, A0, A0, A1, A1)>::type
 *       plnorm(A0 const& a0, A0 const& a1, A0 const& a2, A1 const& a3, A1 const& a4);
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
 * r_mathlib library defines functions for double entries (A0) only,
 * A1 being int entries.
 * Nevertheless, they can be called with float A0 entries under nt2 calls
 * to return float outputs.
 *  
**/

namespace nt2 { namespace r_mathlib { namespace tag
  {         
    /*!
     * \brief Define the tag plnorm_ of functor plnorm 
     *        in namespace nt2::r_mathlib::tag for toolbox r_mathlib
    **/
    struct plnorm_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(r_mathlib::tag::plnorm_, plnorm, 5)
  } }

#include <nt2/toolbox/r_mathlib/functions/scalar/plnorm.hpp>

#endif

// created by jt the 12/6/2011
