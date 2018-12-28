#include "xtensor-r/rarray.hpp"

using namespace Rcpp;

// [[Rcpp::export]]
int test_in_place_modify_cpp(xt::rarray<double>& x)
{
    // check that passing by reference works correctly
    x(0, 0)  = -1000;
    x(9, 2) = 1000;
    return 1;
}