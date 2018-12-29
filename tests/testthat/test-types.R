context("test-types")

x <- array(1:10, c(2, 5))

test_that("int", {
  test_int_cpp(x)
  expect_true(is.integer(x[2,2]))
  expect_equal(x[2, 2], 35L)
})

x <- array(TRUE, c(2, 5))

test_that("lgl", {
  test_lgl_cpp(x)
  expect_equal(x[2, 2], FALSE)
})

x <- array(as.complex(1:10), c(2, 5))

x[1, 1] <- 0 + 1i
x[2, 3] <- 1 + 5i

test_that("stdcomplex", {
  test_stdcomplex_cpp(x)
  expect_equal(x[1, 3], -10+-100i)
})
