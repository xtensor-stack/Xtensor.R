#include "xtensor-r/rarray.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
int test_reshape_cpp(xt::rarray<double>& x)
{
  // reshape in-place
  x.reshape({3, 10});
  return 1;
}
