################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################
cmake_minimum_required(VERSION 2.6)

if( MSVC OR ( WIN32 AND DEFINED CMAKE_CROSSCOMPILING ) )
	set( CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} /EHsc /GR-"       )
	set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Oxs /Gy" )
elseif( CMAKE_COMPILER_IS_GNUCXX )
	set( CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -fexceptions -fno-rtti" )
	set( CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Os -fomit-frame-pointer -finline-small-functions" )
endif()

set(Boost_ADDITIONAL_VERSIONS "1.46" "1.46.0" "1.46.1" "1.47" "1.47.0" "1.48" "1.48.0")
find_package(Boost 1.46.0 REQUIRED)
if(Boost_VERSION LESS 104600)
  message(FATAL_ERROR "Boost version ${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION} not recent enough, needs 1.46.0")
endif()

include_directories(${CMAKE_SOURCE_DIR}/../gather_includes ${Boost_INCLUDE_DIRS})

add_executable(move_reuse move_reuse.cpp)
set_target_properties(move_reuse
                      PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}
                                 RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}
                     )
