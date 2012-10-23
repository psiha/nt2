//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_UNIT_PERFORM_BENCHMARK_HPP_INCLUDED
#define NT2_SDK_UNIT_PERFORM_BENCHMARK_HPP_INCLUDED

#include <nt2/sdk/timing/now.hpp>

#include <vector>
#include <utility>

namespace nt2 { namespace unit
{
  typedef std::pair<nt2::details::cycles_t, nt2::details::microseconds_t> benchmark_result_t;

  static std::vector<nt2::details::cycles_t      > individual_measurement_cycles       ;
  static std::vector<nt2::details::time_quantum_t> individual_measurement_time_quantums;

  template <class Test> inline
  benchmark_result_t perform_benchmark( Test & test, nt2::details::seconds_t const total_duration_in_seconds )
  {
    individual_measurement_cycles       .clear();
    individual_measurement_time_quantums.clear();

    using namespace nt2::details;

    time_quantum_t const total_duration( to_timequantums( total_duration_in_seconds * 1000000 ) );
    time_quantum_t       duration      ( 0                                                      );

    while ( duration < total_duration )
    {
        time_quantum_t const time_start  ( now        () );
        cycles_t       const cycles_start( read_cycles() );
        test();
        cycles_t       const cycles_end  ( read_cycles() );
        time_quantum_t const time_end    ( now        () );

        cycles_t       const burned_cycles( cycles_end - cycles_start - read_cycles_overhead                                         );
        time_quantum_t const elapsed_time ( time_end   - time_start   - now_overhead - ( 2 * read_cycles_overhead_in_time_quantums ) );

    /* "other" version:
        cycles_t       const cycles_start( read_cycles() );
        time_quantum_t const time_start  ( now        () );
        test();
        time_quantum_t const time_end    ( now        () );
        cycles_t       const cycles_end  ( read_cycles() );

        time_quantum_t const elapsed_time ( time_end   - time_start   - now_overhead                                       );
        cycles_t       const burned_cycles( cycles_end - cycles_start - read_cycles_overhead - ( 2 * now_overhead_cycles ) );
    */
        duration += elapsed_time;

        individual_measurement_cycles       .push_back( burned_cycles );
        individual_measurement_time_quantums.push_back( elapsed_time  );
        test.reset();
    }

    return benchmark_result_t
    (
                         median( individual_measurement_cycles        ),
        to_microseconds( median( individual_measurement_time_quantums ) )
    );
  }

} }

#endif
