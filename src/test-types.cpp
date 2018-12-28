#include "xtensor-r/rarray.hpp"

using namespace Rcpp;

void xassert(bool cond)
{
  if (!cond) throw std::runtime_error("CPP ASSERT TRIGGERED.");
}

// [[Rcpp::export]]
int test_int_cpp(xt::rarray<int>& x)
{
  xassert(x(0, 0) == 1);
  xassert(x(0, 2) == 5);
  x(1, 1) = 35;
  return 1;
}

// [[Rcpp::export]]
int test_lgl_cpp(xt::rarray<rlogical>& x)
{
  // R uses ints as logicals
  // 1 = true, 0 = false
  xassert(x(0, 0) == 1);
  x(1, 1) = 0;
  return 1;
}

// [[Rcpp::export]]
int test_stdcomplex_cpp(xt::rarray<std::complex<double>>& x)
{
  using cplx = std::complex<double>;
  xassert(x(0, 0) == cplx(0., 1.));
  xassert(x(1, 2) == cplx(1., 5.));
  x(0, 2) = cplx(-10., -100.);
  return 1;
}
