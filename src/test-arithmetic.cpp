#include "xtensor-r/rarray.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
xt::rarray<double> test_add_cpp(xt::rarray<double>& x, xt::rarray<double>& y)
{
  return x + y;
}