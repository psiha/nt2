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
#include <boost/simd/toolbox/operator/functions/bitwise_and.hpp>
#include <boost/simd/toolbox/operator/functions/bitwise_or.hpp>
#include <boost/simd/toolbox/operator/functions/bitwise_xor.hpp>
#include <boost/simd/toolbox/operator/functions/complement.hpp>
#include <boost/simd/toolbox/operator/functions/divides.hpp>
#include <boost/simd/toolbox/operator/functions/make.hpp>
#include <boost/simd/toolbox/operator/functions/simd/details/make_helper.hpp>
#include <boost/simd/toolbox/operator/functions/minus.hpp>
#include <boost/simd/toolbox/operator/functions/modulo.hpp>
#include <boost/simd/toolbox/operator/functions/multiplies.hpp>
#include <boost/simd/toolbox/operator/functions/plus.hpp>
#include <boost/simd/toolbox/operator/functions/shift_left.hpp>
#include <boost/simd/toolbox/operator/functions/shift_right.hpp>
#include <boost/simd/toolbox/operator/functions/unary_minus.hpp>
#include <boost/simd/toolbox/swar/functions/details/shuffle.hpp>
#include <boost/simd/toolbox/swar/functions/reverse.hpp>
//------------------------------------------------------------------------------
namespace boost
{
namespace simd
{
namespace ext
{

// GCC native vector operators for emulation
#if ( __GNUC__ >= 4 )

#if ( __GNUC_MINOR__ >= 5 )
  #define BOOST_SIMD_HAS_VECTORIZABLE_EMULATION

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
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::modulo_     , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() % a1(); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::unary_minus_, boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
    typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL(1) { return -a0(); }
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
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::complement_ , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
      typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL(1) { _ivec const result( ~( (_ivec const &)a0() ) ); return (result_type const &)result; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::make_       , boost::simd::tag::cpu_, (A0), ((target_<simd_<single_<A0>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
      BOOST_SIMD_MAKE_BODY(4) { return (typename result_type::native_type){ a0, a1, a2, a3 }; }
  };
#endif // GCC 4.5+

#if ( __GNUC_MINOR__ >= 6 )
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_left_ , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
      typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() << a1(); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_right_, boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
      typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() >> a1(); }
  };

  // shifts by scalar
  // subscript access
#endif // GCC 4.6+

#if ( __GNUC_MINOR__ >= 7 )
  // operators ==, !=, <, <=, >, >=
  // splat
#endif // GCC 4.7+
#endif // __GNUC__

#ifdef __ARM_NEON__
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::reverse_, boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
      typedef A0 result_type;
      BOOST_SIMD_FUNCTOR_CALL(1)
      {
          float32x4_t const vector              ( (float32x4_t const &)a0()             );
          float32x4_t const half_reversed_vector( vrev64q_f32  ( vector )               );
          float32x2_t const result_hi           ( vget_low_f32 ( half_reversed_vector ) );
          float32x2_t const result_lo           ( vget_high_f32( half_reversed_vector ) );
          float32x4_t const result              ( vcombine_f32 ( result_lo, result_hi ) );
          return (typename A0::native_type const &)result;
      }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::cpu_, (A0)(A1), (scalar_< fundamental_<A0> >)((target_< simd_< single_<A1>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A1::type result_type;
    result_type operator()(A0 const a0, A1 const&) const
    {
      return (typename result_type::native_type)vmovq_n_f32( a0 );
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::cpu_, (A0)(A1), (scalar_< fundamental_<A0> >)((target_< simd_< uint32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A1::type result_type;
    result_type operator()(A0 const a0, A1 const&) const
    {
      return (typename result_type::native_type)vmovq_n_u32( a0 );
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::cpu_, (A0)(A1), (scalar_< fundamental_<A0> >)((target_< simd_< int32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A1::type result_type;
    result_type operator()(A0 const a0, A1 const&) const
    {
      return (typename result_type::native_type)vmovq_n_s32( a0 );
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_less_, boost::simd::tag::cpu_, (A0), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return (typename result_type::native_type)vcltq_f32( (float32x4_t)a0(), (float32x4_t)a1() ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_greater_equal_, boost::simd::tag::cpu_, (A0), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
      typedef typename meta::as_logical<A0>::type result_type;
      BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return (typename result_type::native_type)vcgeq_f32( (float32x4_t)a0(), (float32x4_t)a1() ); }
  };
#endif // __ARM_NEON__

} // namespace ext

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
#elif !defined( __clang__ ) && defined( __GNUC__ ) && defined( __ARM_NEON__ )
    #if ( ( ( __GNUC__ * 10 ) + __GNUC_MINOR__ ) >= 47 )
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
    #else // GCC w/o builtin shuffle
        typedef float builtin_vector_t __attribute__(( vector_size( 16 ) ));
        template
        <
            unsigned int lower_i0, unsigned int lower_i1,
            unsigned int upper_i0, unsigned int upper_i1
        >
        BOOST_FORCEINLINE builtin_vector_t shuffle( builtin_vector_t const & lower_param, builtin_vector_t const & upper_param )
        {
            uint8x8_t const indices_lower =
            {
                lower_i0 * 4 + 0, lower_i0  * 4 + 1, lower_i0  * 4 + 2, lower_i0  * 4 + 3,
                lower_i1 * 4 + 0, lower_i1  * 4 + 1, lower_i1  * 4 + 2, lower_i1  * 4 + 3,
            };
            uint8x8_t const indices_upper =
            {
                upper_i0 * 4 + 0, upper_i0  * 4 + 1, upper_i0  * 4 + 2, upper_i0  * 4 + 3,
                upper_i1 * 4 + 0, upper_i1  * 4 + 1, upper_i1  * 4 + 2, upper_i1  * 4 + 3,
            };

            uint8x8_t const result_lower_bits( vtbl2_u8( (uint8x8x2_t const &) lower_param, indices_lower ) );
            uint8x8_t const result_upper_bits( vtbl2_u8( (uint8x8x2_t const &) upper_param, indices_upper ) );

            float32x4_t const result( vcombine_f32( (float32x2_t const &)result_lower_bits, (float32x2_t const &)result_upper_bits ) );
            return (builtin_vector_t const &)result;
        }
        template <unsigned int i0, unsigned int i1, unsigned int i2, unsigned int i3>
        BOOST_FORCEINLINE
        builtin_vector_t shuffle( builtin_vector_t const vector )
        {
            return shuffle<i0, i1, i2, i3>( vector, vector );
        }
        template <>
        builtin_vector_t shuffle<1, 0, 3, 2>( builtin_vector_t const vector ) { return (builtin_vector_t)vrev64q_f32( (float32x4_t const &)vector ); }
    #endif

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
