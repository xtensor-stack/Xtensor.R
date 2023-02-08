# ![Xtensor.R](./man/figures/xtensor-r.svg)

[![Travis](https://travis-ci.org/xtensor-stack/Xtensor.R.svg?branch=master)](https://travis-ci.org/xtensor-stack/Xtensor.R)
[![Appveyor](https://ci.appveyor.com/api/projects/status/xk0hlhsk90vex36n?svg=true)](https://ci.appveyor.com/project/xtensor-stack/xtensor-r-7j42j)
[![CRAN status](https://www.r-pkg.org/badges/version/xtensor)](https://CRAN.R-project.org/package=xtensor)
[![Documentation](http://readthedocs.org/projects/xtensor-r/badge/?version=latest)](https://xtensor-r.readthedocs.io/en/latest/?badge=latest)
[![Join the Gitter Chat](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/QuantStack/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

`Xtensor.R` is an R package wrapping the [xtensor-r](https://github.com/xtensor-stack/xtensor-r) bindings
to the [xtensor](https://github.com/xtensor-stack/xtensor) C++ multi-dimensional array library.

## Installation

### From conda-forge

`Xtensor.R` is available on conda-forge, it can be installed with conda, mamba, and rhumba.

```bash
mamba install r-xtensor -c conda-forge
```

### From CRAN

`Xtensor.R` is available on CRAN (The Comprehensive R Archive Network).

```R
install.packages("xtensor")
```

### From the GitHub repository

`Xtensor.R` can be installed from GitHub directly using devtools

```R
devtools::install_github("xtensor-stack/Xtensor.R", ref="package")
```

## Packaging Xtensor.R

*This section may be of interest to people working on packaging Xtensor.R for
Linux distributions or other general-purpose packaging systems.*

The `Xtensor` R package depends on the `xtensor-r` C++ header-only library.

 - When installing the CRAN package the headers of `xtensor-r` and its dependencies
   are vendored in the R package.
 - However, the conda-forge package does not vendor its dependencies.

The vendoring can be prevented by passing the `--novendor` option to the configure script,
which can be passed to the `R CMD INSTALL` command in the following way:

```bash
R CMD INSTALL --build --configure-args='--novendor'
```

## Documentation

To get started with using `Xtensor.R`, check out the documentation at

http://xtensor-r.readthedocs.io/

## Dependencies

`xtensor-r` depends on the `xtensor` and `Rcpp` libraries

| `Xtensor.R`  | `xtensor-r` | `xtensor` | `Rcpp`   |
|--------------|-------------|-----------|----------|
| master       |  ^0.14.2    |  ^0.24.4  | ^1.0     |
| 0.14.1       |  ^0.14.2    |  ^0.24.4  | ^1.0     |
| 0.14.0       |  ^0.14.0    |  ^0.24.0  | ^1.0     |
| 0.13.2       |  ^0.13.0    |  ^0.23.0  | ^1.0     |
| 0.13.1       |  ^0.13.0    |  ^0.23.0  | ^1.0     |
| 0.13.0       |  ^0.13.0    |  ^0.23.0  | ^1.0     |
| 0.12.1       |  ^0.12.1    |  ^0.21.4  | ^1.0     |
| 0.12.0       |  ^0.12.0    |  ^0.21.2  | ^1.0     |
 
## License

We use a shared copyright model that enables all contributors to maintain the copyright on their contributions.

This software is licensed under the BSD-3-Clause license. See the [LICENSE](LICENSE) file for details.
