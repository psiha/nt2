################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(NT2Module)
nt2_module_source_setup(boost.simd.config)

nt2_module_postconfigure(gather_includes --ignore details --ignore impl
                                         --name tags.hpp
                                         boost/simd/sdk/simd/extensions/meta
                                         --out boost/simd/sdk/simd/extensions/meta
                        )

nt2_module_postconfigure(gather_includes --ignore details --ignore impl --ignore detector
                                         --name detect.hpp
                                         boost/simd/sdk/config/details
                                         --out boost/simd/sdk/config/details
                        )

nt2_module_postconfigure(gather_includes --ignore details --ignore impl --ignore detector
                                         --name support.hpp
                                         boost/simd/sdk/config/details
                                         --out boost/simd/sdk/config/details
                        )
