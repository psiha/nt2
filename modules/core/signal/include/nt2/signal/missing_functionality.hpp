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
#include <boost/simd/memory/functions/extract.hpp>
#include <boost/simd/memory/functions/insert.hpp>
#include <boost/simd/memory/functions/load.hpp>
#include <boost/simd/memory/functions/store.hpp>
#include <boost/simd/operator/functions/bitwise_and.hpp>
#include <boost/simd/operator/functions/bitwise_or.hpp>
#include <boost/simd/operator/functions/bitwise_xor.hpp>
#include <boost/simd/operator/functions/complement.hpp>
#include <boost/simd/operator/functions/divides.hpp>
#include <boost/simd/operator/functions/is_less.hpp>
#include <boost/simd/operator/functions/is_greater_equal.hpp>
#include <boost/simd/operator/functions/make.hpp>
#include <boost/simd/operator/functions/simd/details/make_helper.hpp>
#include <boost/simd/operator/functions/minus.hpp>
#include <boost/simd/operator/functions/modulo.hpp>
#include <boost/simd/operator/functions/multiplies.hpp>
#include <boost/simd/operator/functions/plus.hpp>
#include <boost/simd/operator/functions/shift_left.hpp>
#include <boost/simd/operator/functions/shift_right.hpp>
#include <boost/simd/operator/functions/unary_minus.hpp>
#include <boost/simd/swar/functions/details/shuffle.hpp>
#include <boost/simd/swar/functions/deinterleave_first.hpp>
#include <boost/simd/swar/functions/deinterleave_second.hpp>
#include <boost/simd/swar/functions/interleave_first.hpp>
#include <boost/simd/swar/functions/interleave_second.hpp>
#include <boost/simd/swar/functions/reverse.hpp>

#include <boost/simd/memory/iterator.hpp>
#include <boost/simd/sdk/simd/native.hpp>

#include <boost/type_traits/is_const.hpp>
//------------------------------------------------------------------------------
namespace boost
{
//------------------------------------------------------------------------------
namespace simd
{
//------------------------------------------------------------------------------
namespace ext
{
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//
// GCC/Clang native vector operators for emulation
//
////////////////////////////////////////////////////////////////////////////////

#if ( __GNUC__ >= 4 )

#if ( __GNUC_MINOR__ >= 5 ) || defined( __clang__ )
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
  typedef native<unsigned int, BOOST_SIMD_DEFAULT_EXTENSION>::native_type _ivec;
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

#if ( __GNUC_MINOR__ >= 6 ) || defined( __clang__ )
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_left_ , boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
      typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() << a1(); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::shift_right_, boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >))((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
      typedef A0 result_type; BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0() >> a1(); }
  };

  // shifts by scalar
#endif // GCC 4.6+

#if ( __GNUC_MINOR__ >= 7 ) || defined( __clang__ )
  // operators ==, !=, <, <=, >, >=
  // splat
#endif // GCC 4.7+

#if ( __GNUC_MINOR__ >= 8 ) || defined( __clang__ )
  /// \note GCC should support subscript access since version 4.6 but they
  /// "forgot" to add this to the C++ frontend:
  /// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=51033
  /// http://gcc.gnu.org/bugzilla/show_bug.cgi?id=53094
  ///                                         (17.12.2012.) (Domagoj Saric)
  // subscript access
#endif // GCC 4.8+

#endif // __GNUC__


////////////////////////////////////////////////////////////////////////////////
//
// ARM NEON
//
////////////////////////////////////////////////////////////////////////////////

#ifdef __ARM_NEON__
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::reverse_, boost::simd::tag::cpu_, (A0), ((simd_<arithmetic_<A0>, BOOST_SIMD_DEFAULT_EXTENSION >)) )
  {
      typedef A0 result_type;
      BOOST_SIMD_FUNCTOR_CALL(1)
      {
          float32x4_t const half_reversed_vector( vrev64q_f32  ( a0 )                   );
          float32x2_t const result_hi           ( vget_low_f32 ( half_reversed_vector ) );
          float32x2_t const result_lo           ( vget_high_f32( half_reversed_vector ) );
          float32x4_t const result              ( vcombine_f32 ( result_lo, result_hi ) );
          return result;
      }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::deinterleave_first_ , boost::simd::tag::cpu_, (A0)(A1), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A1>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
    typedef A0 result_type;
    //...mrmlj...assume that (de)interleave will always be called in first+second
    //...mrmlj...pairs and that the compiler will issue only a single instruction
    //...mrmlj...(GCC 4.6 does but does not quite generate optimal code for
    //...mrmlj..."N-element vectors/structs")
    //...mrmlj...http://gcc.gnu.org/bugzilla/show_bug.cgi?id=48941
    result_type operator()(float32x4_t const  a0, float32x4_t const a1) const { return vuzpq_f32( a0, a1 ).val[ 0 ]; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::deinterleave_second_, boost::simd::tag::cpu_, (A0)(A1), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A1>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
    typedef A0 result_type;
    result_type operator()(float32x4_t const a0, float32x4_t const a1) const { return vuzpq_f32( a0, a1 ).val[ 1 ]; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::interleave_first_   , boost::simd::tag::cpu_, (A0)(A1), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A1>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
    typedef A0 result_type;
    result_type operator()(float32x4_t const a0, float32x4_t const a1) const { return vzipq_f32( a0, a1 ).val[ 0 ]; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::interleave_second_  , boost::simd::tag::cpu_, (A0)(A1), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A1>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
    typedef A0 result_type;
    result_type operator()(float32x4_t const a0, float32x4_t const a1) const { return vzipq_f32( a0, a1 ).val[ 1 ]; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::cpu_, (A0)(A1), (scalar_< fundamental_<A0> >)((target_< simd_< single_<A1>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A1::type result_type;
    result_type operator()(A0 const a0, A1 const&) const { return vmovq_n_f32( a0 ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::cpu_, (A0)(A1), (scalar_< fundamental_<A0> >)((target_< simd_< uint32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A1::type result_type;
    result_type operator()(A0 const a0, A1 const&) const { return vmovq_n_u32( a0 ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::splat_, boost::simd::tag::cpu_, (A0)(A1), (scalar_< fundamental_<A0> >)((target_< simd_< int32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A1::type result_type;
    result_type operator()(A0 const a0, A1 const&) const { return vmovq_n_s32( a0 ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_less_, boost::simd::tag::cpu_, (A0), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    //...mrmlj...see the note in as_simd around the as_integer<> meta-call...
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return vreinterpretq_s32_u32( vcltq_f32( a0, a1 ) ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::is_greater_equal_, boost::simd::tag::cpu_, (A0), ((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>))((simd_<single_<A0>,BOOST_SIMD_DEFAULT_EXTENSION>)) )
  {
    typedef typename meta::as_logical<A0>::type result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return vreinterpretq_s32_u32( vcgeq_f32( a0, a1 ) ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_, boost::simd::tag::cpu_, (A0)(A1), (iterator_< scalar_< single_<A0> > >)((target_< simd_< single_<A1>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A1::type result_type;
    result_type operator()( A0 const a0, A1 const & ) const { return vld1q_f32( a0 ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::load_ , boost::simd::tag::cpu_, (A0)(A1)(A2), (iterator_< scalar_< single_<A0> > >)(scalar_< fundamental_<A1> >)((target_< simd_< single_<A2>, BOOST_SIMD_DEFAULT_EXTENSION > >)) )
  {
    typedef typename A2::type result_type;
    inline result_type operator()( A0 const a0, A1 const a1, A2 const & ) const { return vld1q_f32( a0 + a1 ); }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::store_ , boost::simd::tag::cpu_, (A0)(A1), ((simd_<single_<A0>, BOOST_SIMD_DEFAULT_EXTENSION>))(iterator_< scalar_< single_<A1> > >) )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL(2) { vst1q_f32( a1, a0 ); return a0; }
  };
#if defined( __GNUC__ ) && !defined( __clang__ )
  //...mrmlj...GCC seems capable of detecting constant integer parameters
  //...mrmlj...through inlined functions even in debug builds while clang does not...
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION
  (
    boost::simd::tag::extract_,
    boost::simd::tag::cpu_,
    (A0)(A1),
    ((simd_<single_<A0>, BOOST_SIMD_DEFAULT_EXTENSION>))(scalar_< integer_<A1> >)
  )
  {
    float operator()( float32x4_t const a0, A1 const a1 ) const { return vgetq_lane_f32( a0, a1 ); }

    //...mrmlj...some code wants non-const references...
    template<class Sig>
    struct result;

    template<class This, class A0_, class A1_>
    struct result<This(A0_, A1_)>
    {
        typedef typename meta::scalar_of<typename remove_reference<A0_>::type>::type stype;
        typedef typename mpl::if_<is_const<stype>, stype, typename meta::may_alias<stype>::type &>::type type;
    };

    template<class A0_>
    BOOST_FORCEINLINE typename result<implement(A0_&, A1 const&)>::type
    operator()( A0_& a0, A1 const a1 ) const
    {
        typedef typename meta::scalar_of<A0_>::type stype;
        return reinterpret_cast<typename meta::may_alias<stype>::type*>(&a0)[a1];
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::insert_, tag::cpu_, (A0)(A1)(A2), (scalar_< arithmetic_<A0> >)((simd_< single_<A1>, BOOST_SIMD_DEFAULT_EXTENSION >))(scalar_< integer_<A2> >) )
  {
    typedef float32x4_t & result_type;
    BOOST_FORCEINLINE result_type operator()( A0 const a0, float32x4_t & a1, int const a2 ) const
    {
      a1 = vsetq_lane_f32( a0, a1, a2 );
      return a1;
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::insert_, tag::cpu_, (A0)(A1)(A2), (scalar_< arithmetic_<A0> >)((simd_< uint32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION >))(scalar_< integer_<A2> >) )
  {
    typedef uint32x4_t & result_type;
    BOOST_FORCEINLINE result_type operator()( A0 const a0, uint32x4_t & a1, int const a2 ) const
    {
      a1 = vsetq_lane_u32( a0, a1, a2 );
      return a1;
    }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::insert_, tag::cpu_, (A0)(A1)(A2), (scalar_< arithmetic_<A0> >)((simd_< int32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION >))(scalar_< integer_<A2> >) )
  {
    typedef int32x4_t & result_type;
    BOOST_FORCEINLINE result_type operator()( A0 const a0, int32x4_t & a1, int const a2 ) const
    {
      a1 = vsetq_lane_s32( a0, a1, a2 );
      return a1;
    }
  };
#endif // __GNUC__ && !__clang__

#endif // __ARM_NEON__

#if defined( __clang__ )
  //...mrmlj...clang has subscript operator support...
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION
  (
    boost::simd::tag::extract_,
    boost::simd::tag::cpu_,
    (A0)(A1),
    ((simd_<single_<A0>, BOOST_SIMD_DEFAULT_EXTENSION>))(scalar_< integer_<A1> >)
  )
  {
    //...mrmlj...some code wants non-const references...
    template<class Sig>
    struct result;
    template<class This, class A0_, class A1_>
    struct result<This(A0_, A1_)>
    {
        typedef typename meta::scalar_of<typename remove_reference<A0_>::type>::type stype;
        typedef typename mpl::if_<is_const<stype>, stype, typename meta::may_alias<stype>::type &>::type type;
    };
    float   operator()( A0 const & a0, A1 const a1 ) const { return a0()[ a1 ]; }
    float & operator()( A0       & a0, A1 const a1 ) const { return reinterpret_cast<typename meta::may_alias<float>::type*>(&(a0()))[ a1 ]; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::insert_, tag::cpu_, (A0)(A1)(A2), (scalar_< arithmetic_<A0> >)((simd_< single_<A1>, BOOST_SIMD_DEFAULT_EXTENSION >))(scalar_< integer_<A2> >) )
  {
    typedef A1 & result_type;
    BOOST_FORCEINLINE result_type operator()( A0 const a0, A1 & a1, int const a2 ) const { a1()[ a2 ] = a0; return a1; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::insert_, tag::cpu_, (A0)(A1)(A2), (scalar_< arithmetic_<A0> >)((simd_< uint32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION >))(scalar_< integer_<A2> >) )
  {
    typedef A1 & result_type;
    BOOST_FORCEINLINE result_type operator()( A0 const a0, A1 & a1, int const a2 ) const { a1()[ a2 ] = a0; return a1; }
  };
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::insert_, tag::cpu_, (A0)(A1)(A2), (scalar_< arithmetic_<A0> >)((simd_< int32_<A1>, BOOST_SIMD_DEFAULT_EXTENSION >))(scalar_< integer_<A2> >) )
  {
    typedef A1 & result_type;
    BOOST_FORCEINLINE result_type operator()( A0 const a0, A1 & a1, int const a2 ) const { a1()[ a2 ] = a0; return a1; }
  };
#endif // __clang__

//------------------------------------------------------------------------------
} // namespace ext
//------------------------------------------------------------------------------
namespace details
{
//------------------------------------------------------------------------------

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
#elif defined( __clang__ )
    template
    <
        unsigned int lower_i0, unsigned int lower_i1,
        unsigned int upper_i0, unsigned int upper_i1,
        typename Vector
    >
    BOOST_FORCEINLINE Vector shuffle( Vector const & lower, Vector const & upper )
    {
        return __builtin_shufflevector( lower(), upper(), 0 + lower_i0, 0 + lower_i1, 4 + upper_i0, 4 + upper_i1 );
    }

    template
    <
        unsigned int i0, unsigned int i1, unsigned int i2, unsigned int i3,
        typename Vector
    >
    BOOST_FORCEINLINE Vector shuffle( Vector const & vector )
    {
        return shuffle<i0, i1, i2, i3>( vector, vector );
    }
#elif defined( __GNUC__ ) && defined( __ARM_NEON__ )
    #if ( ( ( __GNUC__ * 10 ) + __GNUC_MINOR__ ) >= 47 ) && !defined( __ANDROID__ ) //...mrmlj...does not seem to work with the r8e gcc 4.7??
        typedef native<unsigned int, BOOST_SIMD_DEFAULT_EXTENSION>::native_type shuffle_mask_t;
        template
        <
            unsigned int lower_i0, unsigned int lower_i1,
            unsigned int upper_i0, unsigned int upper_i1,
            typename Vector
        >
        BOOST_FORCEINLINE Vector shuffle( Vector const & lower, Vector const & upper )
        {
          static shuffle_mask_t const mask = { 0 + lower_i0, 0 + lower_i1, 4 + upper_i0, 4 + upper_i1 };
          return __builtin_shuffle( lower, upper, mask );
        }

        template
        <
            unsigned int i0, unsigned int i1, unsigned int i2, unsigned int i3,
            typename Vector
        >
        BOOST_FORCEINLINE Vector shuffle( Vector const & vector )
        {
          static shuffle_mask_t const mask = { i0, i1, i2, i3 };
          return __builtin_shuffle( vector, mask );
        }
    #else // GCC w/o builtin shuffle
        typedef native<float, BOOST_SIMD_DEFAULT_EXTENSION>::native_type builtin_vector_t;
        template
        <
            unsigned int lower_i0, unsigned int lower_i1,
            unsigned int upper_i0, unsigned int upper_i1
        >
        BOOST_FORCEINLINE builtin_vector_t shuffle( builtin_vector_t const lower, builtin_vector_t const upper )
        {
            static uint8x8_t const indices_lower =
            {
                lower_i0 * 4 + 0, lower_i0  * 4 + 1, lower_i0  * 4 + 2, lower_i0  * 4 + 3,
                lower_i1 * 4 + 0, lower_i1  * 4 + 1, lower_i1  * 4 + 2, lower_i1  * 4 + 3,
            };
            static uint8x8_t const indices_upper =
            {
                upper_i0 * 4 + 0, upper_i0  * 4 + 1, upper_i0  * 4 + 2, upper_i0  * 4 + 3,
                upper_i1 * 4 + 0, upper_i1  * 4 + 1, upper_i1  * 4 + 2, upper_i1  * 4 + 3,
            };

            uint8x8_t const result_lower_bits( vtbl2_u8( (uint8x8x2_t const &)/*vreinterpretq_u8_f32*/( lower ), indices_lower ) );
            uint8x8_t const result_upper_bits( vtbl2_u8( (uint8x8x2_t const &)/*vreinterpretq_u8_f32*/( upper ), indices_upper ) );

            return vcombine_f32( vreinterpret_f32_u8( result_lower_bits ), vreinterpret_f32_u8( result_upper_bits ) );
        }
        template <unsigned int i0, unsigned int i1, unsigned int i2, unsigned int i3>
        BOOST_FORCEINLINE
        builtin_vector_t shuffle( builtin_vector_t const vector )
        {
            return shuffle<i0, i1, i2, i3>( vector, vector );
        }
        template <>
        builtin_vector_t shuffle<1, 0, 3, 2>( builtin_vector_t const vector ) { return vrev64q_f32( vector ); }
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

//------------------------------------------------------------------------------
} // namespace details
//------------------------------------------------------------------------------
} // namespace simd
//------------------------------------------------------------------------------
} // namespace boost
//------------------------------------------------------------------------------

#endif // MISSING_FUNCTIONALITY_HPP_INCLUDED
