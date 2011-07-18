//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_OPERATOR_SPECIFIC_COMPARE_TAGS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_OPERATOR_SPECIFIC_COMPARE_TAGS_HPP_INCLUDED

namespace boost { namespace dispatch
{
  namespace tag
  {
    struct compare_equal_   {};    struct compare_not_equal_     {};
    struct compare_greater_ {};    struct compare_greater_equal_ {};
    struct compare_less_    {};    struct compare_less_equal_    {};
  }
} }

#endif
