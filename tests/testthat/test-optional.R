context("test-optional")

x <- matrix(c(1, NA_real_, 2, NA_real_, 4, 5), ncol = 2)

test_that("can roundtrip optional rarray and rtensors", {
  expect_equal(test_roundtrip_rarray_optional(x), x)
  expect_equal(test_roundtrip_rtensor_optional(x), x)
})

