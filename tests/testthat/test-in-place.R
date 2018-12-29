context("test-in place modification")

x <- array(as.numeric(1:100), dim = c(10, 10))

test_that("modify in place", {
	expect_equal(x[1, 1], 1)
	expect_equal(x[10, 3], 30)
	expect_equal(test_in_place_modify_cpp(x), 1)
	expect_equal(x[2, 3], 22)
	expect_equal(x[1, 1], -1000)
	expect_equal(x[10, 3], 1000)
})