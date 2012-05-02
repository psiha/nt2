//==============================================================================
//         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_FUNCTOR_PREPROCESSOR_CALL_HPP_INCLUDED
#define NT2_SDK_FUNCTOR_PREPROCESSOR_CALL_HPP_INCLUDED

#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <nt2/sdk/functor/hierarchy.hpp>

#define NT2_FUNCTOR_CALL(N) BOOST_DISPATCH_CALL(N)
#define NT2_FUNCTOR_CALL_REPEAT(N) BOOST_DISPATCH_CALL_REPEAT(N)

#define NT2_FUNCTOR_IMPLEMENTATION(Tag, Site, Types, Seq)                                          \
BOOST_DISPATCH_REGISTER_TO_WITH( (nt2)(ext), nt2::tag::Tag, Site                                   \
                               , (boost)(dispatch)(meta)(BOOST_PP_CAT(dispatching_, Tag))          \
                               , Types, Seq                                                        \
                               , ( nt2::ext::                                                      \
                                   BOOST_DISPATCH_IMPLEMENT_(nt2::tag::Tag, Site, Seq)             \
                                 )                                                                 \
                               )                                                                   \
BOOST_DISPATCH_IMPLEMENT_BODY(nt2::tag::Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)                \
/**/

#define NT2_FUNCTOR_IMPLEMENTATION_TPL(Tag, Site, Types, Seq)                                      \
BOOST_DISPATCH_REGISTER_TPL_TO_WITH( (nt2)(ext), nt2::tag::Tag, Site                               \
                               , (boost)(dispatch)(meta)(BOOST_PP_CAT(dispatching_, Tag))          \
                               , Types, Seq                                                        \
                               , ( nt2::ext::                                                      \
                                   BOOST_DISPATCH_IMPLEMENT_(nt2::tag::Tag, Site, Seq)             \
                                 )                                                                 \
                               )                                                                   \
BOOST_DISPATCH_IMPLEMENT_BODY(nt2::tag::Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE_TPL)            \
/**/

#define NT2_FUNCTOR_IMPLEMENTATION_IF(Tag, Site, Types, Cond, Seq)                                 \
BOOST_DISPATCH_REGISTER_TO_IF_WITH( (nt2)(ext), nt2::tag::Tag, Site                                \
                               , (boost)(dispatch)(meta)(BOOST_PP_CAT(dispatching_, Tag))          \
                               , Types, Cond, Seq                                                  \
                               , ( nt2::ext::                                                      \
                                   BOOST_DISPATCH_IMPLEMENT_(nt2::tag::Tag, Site, Seq)             \
                                 )                                                                 \
                               )                                                                   \
BOOST_DISPATCH_IMPLEMENT_BODY(nt2::tag::Tag, Site, Types, Seq, BOOST_DISPATCH_TYPE)                \
/**/

#define NT2_FUNCTOR_IMPLEMENTATION_GEN(Tag, Site, Types, Seq)                                      \
BOOST_DISPATCH_IMPLEMENT((nt2)(ext), Tag, Site, Types, Seq)

#define NT2_FUNCTOR_IMPLEMENTATION_IF_GEN(Tag, Site, Types, Cond, Seq)                             \
BOOST_DISPATCH_IMPLEMENT_IF((nt2)(ext), Tag, Site, Types, Cond, Seq)

#endif
