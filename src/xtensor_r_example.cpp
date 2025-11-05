#include "xtensor-r/rcontainer.hpp"
#include "xtensor-r/rarray.hpp"
#include "xtensor-r/rtensor.hpp"

#include "xtensor/io/xio.hpp"
#include "xtensor/io/xinfo.hpp"
#include "xtensor/containers/xarray.hpp"

#include <Rcpp.h>

// [[Rcpp::plugins(cpp14)]]

// [[Rcpp::export]]
xt::rtensor<double, 2> xtensor_r_example(xt::rtensor<int, 1> tens)
{
    auto t = xt::rtensor<double, 2>({{1, 2, 3}, {5, 5, 5}});
    auto x = xt::rarray<double>({{1, 2, 3}, {5, 5, 5}});
    xt::rarray<double> rarr = t * x + 2;
    return t * x;
}
