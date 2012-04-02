//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_CORE_FUNCTIONS_COMMON_BAND_HPP_INCLUDED
#define NT2_CORE_FUNCTIONS_COMMON_BAND_HPP_INCLUDED

#include <nt2/core/functions/band.hpp>
#include <nt2/include/functions/run.hpp>
#include <nt2/include/constants/zero.hpp>
#include <nt2/include/functions/splat.hpp>
#include <nt2/include/functions/if_else.hpp>
#include <nt2/include/functions/enumerate.hpp>
#include <nt2/include/functions/ge.hpp>
#include <nt2/include/functions/le.hpp>
#include <nt2/include/functions/eq.hpp>
#include <nt2/include/functions/logical_and.hpp>

namespace nt2 { namespace ext
{
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::band_, N>))
                              (fusion_sequence_<State>)
                              ((unspecified_<Data>))
                            )
  {
    typedef typename meta::strip<Data>::type::type result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      typedef typename meta::as_integer<result_type>::type i_type;
      return nt2::if_else
        ( nt2::eq ( nt2::enumerate<i_type>( boost::fusion::at_c<0>(p) ), 
                    nt2::splat<i_type>    ( boost::fusion::at_c<1>(p) )
                    ), 
          nt2::run(boost::proto::child_c<0>(a0),p,t), 
          Zero<result_type>()
          );
    }
  };

  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::offset_band1_, N>))
                              (fusion_sequence_<State>)
                              ((unspecified_<Data>))
                            )
  {
    typedef typename meta::strip<Data>::type::type result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      typedef typename meta::as_integer<result_type>::type i_type;
      i_type iis   = nt2::enumerate<i_type>( boost::fusion::at_c<0>(p) );
      i_type jjsup = nt2::splat<i_type>( boost::fusion::at_c<1>(p)+
                                              boost::proto::value(boost::proto::child_c<1>(a0)) );
      i_type jjsdn = nt2::splat<i_type>( boost::fusion::at_c<1>(p)-
                                              boost::proto::value(boost::proto::child_c<1>(a0)) );
      return nt2::if_else( nt2::logical_and(nt2::le(iis,jjsup), nt2::ge(iis,jjsdn)), 
                           nt2::run(boost::proto::child_c<0>(a0),p,t), 
                           Zero<result_type>()
                           );
    }
  };
  
  NT2_FUNCTOR_IMPLEMENTATION( nt2::tag::run_, tag::cpu_
                            , (A0)(State)(Data)(N)
                            , ((node_<A0, nt2::tag::offset_band2_, N>))
                              (fusion_sequence_<State>)
                              ((unspecified_<Data>))
                            )
  {
    typedef typename meta::strip<Data>::type::type result_type;

    BOOST_FORCEINLINE result_type
    operator()(A0 const& a0, State const& p, Data const& t) const
    {
      typedef typename meta::as_integer<result_type>::type i_type;
      i_type iis   = nt2::enumerate<i_type>( boost::fusion::at_c<0>(p) );
      i_type jjsup = nt2::splat<i_type>( boost::fusion::at_c<1>(p)+
                                              boost::proto::value(boost::proto::child_c<2>(a0)) );
      i_type jjsdn = nt2::splat<i_type>( boost::fusion::at_c<1>(p)-
                                              boost::proto::value(boost::proto::child_c<1>(a0)) );
      return nt2::if_else( nt2::logical_and(nt2::le(iis,jjsup), nt2::ge(iis,jjsdn)), 
                           nt2::run(boost::proto::child_c<0>(a0),p,t), 
                           Zero<result_type>()
                           );
    }
  };

} }

#endif
