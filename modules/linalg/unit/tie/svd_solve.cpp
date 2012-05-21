//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 linalg toolbox - tied lsq_lse_solve function"

#include <nt2/table.hpp>
#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/include/functions/eye.hpp> 
#include <nt2/include/functions/lsq_lse_solve.hpp>
#include <nt2/include/functions/tie.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/exceptions.hpp>

NT2_TEST_CASE_TPL ( lsq_lse_solve_expr, NT2_REAL_TYPES)
{
  typedef typename nt2::meta::as_integer<T, signed>::type itype_t; 
  typedef nt2::table<T> t_t;
  typedef nt2::table<itype_t> it_t; 
  t_t a = nt2::expand(nt2::triu(nt2::ones(4, 4, nt2::meta::as_<T>())), 2, 4);
  a(2, 2) = T(0); 
  t_t b = nt2::expand(T(2)*nt2::eye (4, 4, nt2::meta::as_<T>()), 2, 4);
  b(2, 3) = T(1); 
  t_t c = _(T(4), T(-1), T(3))(_);
  t_t d = T(2)*nt2::ones(2, 1, nt2::meta::as_<T>());
  nt2::disp("a     ", a); 
  nt2::disp("b     ", b);
  nt2::disp("c     ", c);
  nt2::disp("d     ", d);

  nt2::tie(x, residuals, status) = nt2::lsq_lse_solve(a, b, c, d);
  NT2_DISP(x);
  NT2_DISP(residuals);
  std::cout << "status" << status << std::endl; 

}
