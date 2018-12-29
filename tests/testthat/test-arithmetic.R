context("test-arithmetic")

x <- array(as.numeric(1:100), dim=c(10, 10))
y <- array(as.numeric(1:100), dim=c(10, 10))

test_that("cpp_add", {
  expect_equal(test_add_cpp(x, y), x + y)
})

