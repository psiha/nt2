//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SWAR_FUNCTIONS_SCALAR_GROUP_HPP_INCLUDED
#define BOOST_SIMD_SWAR_FUNCTIONS_SCALAR_GROUP_HPP_INCLUDED

#include <boost/simd/swar/functions/group.hpp>
#include <boost/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT         ( group_, tag::cpu_
                                   , (A0)
                                   , (scalar_< unspecified_<A0> >)
                                   )
  {
    typedef typename dispatch::meta::downgrade<A0>::type result_type;
    BOOST_FORCEINLINE result_type operator()(A0 const& a0) const
    {
      return result_type(a0);
    }
  };
} } }

#endif
