//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TRIGONOMETRIC_FUNCTIONS_SIND_HPP_INCLUDED
#define NT2_TRIGONOMETRIC_FUNCTIONS_SIND_HPP_INCLUDED
#include <nt2/include/functor.hpp>


namespace nt2 { namespace tag
  {
   /*!
     @brief sind generic tag

     Represents the sind function in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct sind_ : ext::elementwise_<sind_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<sind_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_sind_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
   template<class Site, class... Ts>
   BOOST_FORCEINLINE generic_dispatcher<tag::sind_, Site> dispatching_sind_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
   {
     return generic_dispatcher<tag::sind_, Site>();
   }
   template<class... Args>
   struct impl_sind_;
  }
  /*!
    sine of the angle in degree.

    @par Semantic:

    For every parameter of floating type T0

    @code
    T0 r = sind(x);
    @endcode

    is similar to:

    @code
    T0 r = sin(Deginrad<T0>()*x);
    @endcode

    @see @funcref{sine}, @funcref{fast_sin}, @funcref{sincosd}, @funcref{sin}, @funcref{sinpi}
    @param a0

    @return a value of the same type as the parameter
  **/
  NT2_FUNCTION_IMPLEMENTATION(tag::sind_, sind, 1)
}

#endif


