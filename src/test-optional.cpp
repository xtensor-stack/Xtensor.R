#include "xtensor-r/rarray.hpp"
#include "xtensor-r/roptional.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
xt::rarray_optional<double> test_roundtrip_rarray_optional(xt::rarray_optional<double> x)
{
  return x;
}

// [[Rcpp::export]]
xt::rtensor_optional<double, 2> test_roundtrip_rtensor_optional(xt::rtensor_optional<double, 2> x)
{
  return x;
}