//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_POTRF_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_POTRF_HPP_INCLUDED

/*!
  @file
  @brief Defines and implements lapack potrf function that computes the
  cholesky factorization for a real symmetric positive definite matrix.
**/

#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace tag
  {
    /// @brief Defines gesvx function tag
    struct potrf_ : ext::abstract_<potrf_>
    {
      /// INTERNAL ONLY
      typedef ext::abstract_<potrf_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_potrf_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site, class... Ts>
    BOOST_FORCEINLINE generic_dispatcher<tag::potrf_, Site> dispatching_potrf_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
    {
      return generic_dispatcher<tag::potrf_, Site>();
    }
    template<class... Args>
    struct impl_potrf_;
  }

  /*!
    @brief

    @param
    @param

    @return
  **/

  NT2_FUNCTION_IMPLEMENTATION_TPL (tag::potrf_, potrf
                                  , (A0&)(A1 const&)
                                  , 2
                                  );

}

#endif
