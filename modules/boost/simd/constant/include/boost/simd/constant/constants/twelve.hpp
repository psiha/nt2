//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_CONSTANT_CONSTANTS_TWELVE_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CONSTANTS_TWELVE_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/simd/sdk/constant/register.hpp>
#include <boost/simd/sdk/constant/constant.hpp>

/*!
 * \ingroup boost_simd_constant
 * \defgroup boost_simd_constant_twelve Twelve
 *
 * \par Description
 * Constant Twelve = 12
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/twelve.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::twelve_(A0)>::type
 *     Twelve();
 * }
 * \endcode
 *
 *
 * \param T template parameter of Twelve
 *
 * \return type T value
 *
 *
**/

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
     * \brief Define the tag Twelve of functor Twelve
     *        in namespace boost::simd::tag for toolbox boost.simd.constant
    **/
    BOOST_SIMD_CONSTANT_REGISTER( Twelve, double, 12
                                ,0x41400000, 0x4028000000000000ll
                                );
  }

  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Twelve, Twelve)
} }

#include <boost/simd/sdk/constant/common.hpp>

#endif
