//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_DISPATCH_FUNCTOR_DETAILS_CALL_HPP_INCLUDED
#define BOOST_DISPATCH_FUNCTOR_DETAILS_CALL_HPP_INCLUDED

#include <boost/mpl/bool.hpp>

// Forward declare the unknown_ tag
namespace boost { namespace dispatch { namespace tag { struct unknown_;    } } }

//==========================================================================
/*
 * If you get an error here, you tried to call a function not supported
 * or implemented for values of the given types.
 * Check that you included the proper toolbox or use the correct types in
 * your function call.
 */
//==========================================================================
template<class Call, class Site>
struct BOOST_DISPATCH_UNSUPPORTED_FUNCTION_CALL;

namespace boost { namespace dispatch { namespace meta
{
  template<class T>
  struct is_unsupported
   : boost::mpl::false_
  {
  };

  template<class Site, class Dummy>
  struct is_unsupported< implement<tag::unknown_, Site, Dummy> >
   : boost::mpl::true_
  {
  };

  // Calls to unknown functions end up as errors or as SFINAE
  template<class Site, class Dummy>
  struct implement<tag::unknown_, Site, Dummy>
  {
    //typedef BOOST_DISPATCH_UNSUPPORTED_FUNCTION_CALL<Dummy, Site> result_type;
  };
} } }

#endif
