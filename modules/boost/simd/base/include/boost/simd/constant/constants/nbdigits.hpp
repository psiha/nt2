//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_CONSTANT_CONSTANTS_NBDIGITS_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CONSTANTS_NBDIGITS_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/simd/meta/int_c.hpp>
#include <boost/simd/constant/hierarchy.hpp>


namespace boost { namespace simd
{
  namespace tag
  {
   /*!
     @brief Nbdigits generic tag

     Represents the Nbdigits constant in generic contexts.

     @par Models:
        Hierarchy
   **/
    struct Nbdigits : ext::pure_constant_<Nbdigits>
    {
      typedef double default_type;
      typedef ext::pure_constant_<Nbdigits> parent;

      /// INTERNAL ONLY
      template<class Target, class Dummy=void>
      struct  apply : meta::int_c <typename Target::type,0> {};
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_Nbdigits( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };

    /// INTERNAL ONLY
    template<class T, class Dummy>
    struct  Nbdigits::apply<boost::dispatch::meta::single_<T>,Dummy>
          : meta::int_c<boost::simd::int32_t,24> {};

    /// INTERNAL ONLY
    template<class T, class Dummy>
    struct  Nbdigits::apply<boost::dispatch::meta::double_<T>,Dummy>
          : meta::int_c<boost::simd::int64_t,53> {};
  }
  namespace ext
  {
   template<class Site, class... Ts>
   BOOST_FORCEINLINE generic_dispatcher<tag::Nbdigits, Site> dispatching_Nbdigits(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
   {
     return generic_dispatcher<tag::Nbdigits, Site>();
   }
   template<class... Args>
   struct impl_Nbdigits;
  }
  /*!
    Generates the number of mantissa bits of a floating point number,
    and the total number of bits for integral types.

    @par Semantic:

    @code
    T r = Nbdigits<T>();
    @endcode

    is similar to:

    @code
    if T is integral
      r = sizeof(T)*8
    else if T is double
      r =  53;
    else if T is float
      r =  24;
    @endcode

  **/
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Nbdigits, Nbdigits)
} }

#include <boost/simd/constant/common.hpp>

#endif
