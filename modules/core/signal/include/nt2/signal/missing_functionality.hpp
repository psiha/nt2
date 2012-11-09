//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2012          Domagoj Saric, Little Endian Ltd.
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef MISSING_FUNCTIONALITY_HPP_INCLUDED
#define MISSING_FUNCTIONALITY_HPP_INCLUDED
//------------------------------------------------------------------------------
#include <boost/simd/include/functions/simd/bitwise_and.hpp>
#include <boost/simd/include/functions/simd/bitwise_or.hpp>
#include <boost/simd/include/functions/simd/bitwise_xor.hpp>
#include <boost/simd/include/functions/simd/divides.hpp>
#include <boost/simd/include/functions/simd/minus.hpp>
#include <boost/simd/include/functions/simd/multiplies.hpp>
#include <boost/simd/include/functions/simd/plus.hpp>
#include <boost/simd/toolbox/swar/functions/details/shuffle.hpp>
//------------------------------------------------------------------------------
namespace boost
{
namespace simd
{
#ifdef __GNUC__
namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::minus_      , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() - a1(); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::plus_       , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() + a1(); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::multiplies_ , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() * a1(); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divides_    , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() / a1(); }
  };
  //...mrmlj....
  typedef int _ivec  __attribute__(( vector_size( 16 ), aligned( 16 ) ));
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_and_, boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { _ivec const result( (_ivec const &)a0() & (_ivec const &)a1() ); return (result_type const &)result; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_or_ , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { _ivec const result( (_ivec const &)a0() | (_ivec const &)a1() ); return (result_type const &)result; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitwise_xor_, boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { _ivec const result( (_ivec const &)a0() ^ (_ivec const &)a1() ); return (result_type const &)result; }
  };
} // namespace ext
#endif // __GNUC__

namespace details
{
    ////////////////////////////////////////////////////////////////////////////
    // Shuffles
    ////////////////////////////////////////////////////////////////////////////

#if defined( BOOST_SIMD_HAS_SSE_SUPPORT )
    template <> BOOST_FORCEINLINE __m128 shuffle<0, 1, 0, 1>( __m128 const lower, __m128 const upper ) { return _mm_movelh_ps( lower, upper ); }
    template <> BOOST_FORCEINLINE __m128 shuffle<2, 3, 2, 3>( __m128 const lower, __m128 const upper ) { return _mm_movehl_ps( upper, lower ); }

    template <> BOOST_FORCEINLINE __m128 shuffle<0, 0, 1, 1>( __m128 const single_vector ) { return _mm_unpacklo_ps( single_vector, single_vector ); }
    template <> BOOST_FORCEINLINE __m128 shuffle<2, 2, 3, 3>( __m128 const single_vector ) { return _mm_unpackhi_ps( single_vector, single_vector ); }

    #ifdef BOOST_SIMD_HAS_SSE2_SUPPORT
    template <> BOOST_FORCEINLINE __m128 shuffle<0, 1, 2, 3>( __m128 const lower, __m128 const upper ) { return _mm_castpd_ps( _mm_move_sd( _mm_castps_pd( upper ), _mm_castps_pd( lower ) ) ); }
    #endif // BOOST_SIMD_HAS_SSE2_SUPPORT

    #ifdef BOOST_SIMD_HAS_SSE3_SUPPORT
    template <> BOOST_FORCEINLINE __m128 shuffle<0, 1, 0, 1>( __m128 const single_vector ) { return _mm_castpd_ps( _mm_movedup_pd( _mm_castps_pd( single_vector ) ) ); }
    template <> BOOST_FORCEINLINE __m128 shuffle<0, 0, 2, 2>( __m128 const single_vector ) { return _mm_moveldup_ps( single_vector ); }
    template <> BOOST_FORCEINLINE __m128 shuffle<1, 1, 3, 3>( __m128 const single_vector ) { return _mm_movehdup_ps( single_vector ); }
    #endif // BOOST_SIMD_HAS_SSE3_SUPPORT

    //...zzz...to be continued...
    //_mm_insert_* + _mm_extract_*
    //_mm_blend_*
    //_mm_move_s*
    //_mm_unpackhi_*
    //_mm_unpacklo_*
#elif defined( __GNUC__ ) && !defined( __clang__ ) && ( ( ( __GNUC__ * 10 ) + __GNUC_MINOR__ ) > 46 )
    typedef int shuffle_mask_t __attribute__(( vector_size( 16 ) ));
    template
    <
        unsigned int lower_i0, unsigned int lower_i1,
        unsigned int upper_i0, unsigned int upper_i1,
        typename Vector
    >
    BOOST_FORCEINLINE Vector shuffle( Vector const & lower, Vector const & upper )
    {
      shuffle_mask_t const mask = { 0 + lower_i0, 0 + lower_i1, 4 + upper_i0, 4 + upper_i1 };
      return __builtin_shuffle( lower, upper, mask );
    }

    template
    <
        unsigned int i0, unsigned int i1, unsigned int i2, unsigned int i3,
        typename Vector
    >
    BOOST_FORCEINLINE Vector shuffle( Vector const & vector )
    {
      shuffle_mask_t const mask = { i0, i1, i2, i3 };
      return __builtin_shuffle( vector, mask );
    }
#else
    template
    <
        unsigned int lower_i0, unsigned int lower_i1,
        unsigned int upper_i0, unsigned int upper_i1,
        typename Vector
    >
    BOOST_FORCEINLINE
    Vector shuffle( Vector const & lower, Vector const & upper )
    {
        Vector result;
        result[ 0 ] = lower[ lower_i0 ];
        result[ 1 ] = lower[ lower_i1 ];
        result[ 2 ] = upper[ upper_i0 ];
        result[ 3 ] = upper[ upper_i1 ];
        return result;
    }

    template
    <
        unsigned int i0, unsigned int i1, unsigned int i2, unsigned int i3,
        typename Vector
    >
    BOOST_FORCEINLINE
    Vector shuffle( Vector const & vector )
    {
        return shuffle<i0, i1, i2, i3>( vector, vector );
    }
#endif // BOOST_SIMD_HAS_SSE_SUPPORT

} // namespace details
} // namespace simd
} // namespace boost
#endif // MISSING_FUNCTIONALITY_HPP_INCLUDED
