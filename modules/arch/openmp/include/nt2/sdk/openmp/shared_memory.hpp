//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_OPENMP_SHARED_MEMORY_HPP_INCLUDED
#define NT2_SDK_OPENMP_SHARED_MEMORY_HPP_INCLUDED

#include <boost/dispatch/functor/forward.hpp>
#include <nt2/sdk/shared_memory/shared_memory.hpp>

namespace nt2 { namespace tag
{
  template<typename Site> struct openmp_ : shared_memory_< openmp_<Site>, Site >
  {
    typedef shared_memory_< openmp_<Site>, Site > parent;
  };
} }

#ifdef _OPENMP

#define NT2_HAS_SHARED_MEMORY
namespace nt2
{
  template<typename Site> using shared_memory_site = tag::openmp_<Site>;
}

#include <nt2/sdk/openmp/spawner.hpp>
#include <nt2/sdk/openmp/future.hpp>

#else

namespace nt2
{
  template<typename Site> using shared_memory_site = Site;
}

#endif
#endif
