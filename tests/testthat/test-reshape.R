context("test-reshape")

x <- array(as.numeric(1:30), dim=c(1, 10, 3))

test_that("reshape", {
  expect_equal(dim(x), c(1, 10, 3))
  test_reshape_cpp(x)
  expect_equal(dim(x), c(3, 10))
})