############################################################################
# Copyright (c) 2016, Wolf Vollprecht, Johan Mabille and Sylvain Corlay    #
#                                                                          #
# Distributed under the terms of the BSD 3-Clause License.                 #
#                                                                          #
# The full license is in the file LICENSE, distributed with this software. #
############################################################################

cmake_minimum_required(VERSION 3.1)
project(Xtensor.R)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# Dependencies
# ============

find_package(R REQUIRED)

# Versionning
# ===========

set(XTL_VERSION 0.5.2)
set(XTENSOR_VERSION 0.19.0)
set(XTENSOR_R_VERSION 0.9.0)

# R Package Target
# ================

file(COPY ${CMAKE_SOURCE_DIR}/R-package DESTINATION ${CMAKE_BINARY_DIR})

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/R-package/inst)

include(ExternalProject)
ExternalProject_Add(xtl-clone
    GIT_REPOSITORY https://github.com/QuantStack/xtl
    GIT_TAG ${XTL_VERSION}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
)
set_target_properties(xtl-clone PROPERTIES EXCLUDE_FROM_ALL TRUE)

ExternalProject_Add(xtensor-clone
    GIT_REPOSITORY https://github.com/QuantStack/xtensor
    GIT_TAG ${XTENSOR_VERSION}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
)
set_target_properties(xtensor-clone PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_dependencies(xtensor-clone xtl-clone)

ExternalProject_Add(xtensor-r-clone
    GIT_REPOSITORY https://github.com/QuantStack/xtensor-r
    GIT_TAG ${XTENSOR_R_VERSION}
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION} -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
)
set_target_properties(xtensor-r-clone PROPERTIES EXCLUDE_FROM_ALL TRUE)
add_dependencies(xtensor-r-clone  xtensor-clone xtl-clone)

add_custom_target(cran DEPENDS xtensor-clone xtl-clone xtensor-r-clone)

OPTION(XTENSOR_INSTALL_R_PACKAGES "Install Rcpp and devtools from CRAN" ON)

if (XTENSOR_INSTALL_R_PACKAGES)
    # Install Rcpp and devtools
    add_custom_command(
        TARGET cran
        POST_BUILD
        COMMAND ${R_COMMAND} -q -e \"install.packages\(c\(\'Rcpp\',\'devtools\'\),repos=\'http://cran.us.r-project.org\'\)\"
    )
endif()

# Run Rcpp compileAttributes
add_custom_command(
    TARGET cran
    POST_BUILD
    COMMAND ${R_COMMAND} -q -e \"library\(\'Rcpp\'\)\;Rcpp::compileAttributes\(\'R-package\'\)\;\"
)

# Run devtools build
add_custom_command(
    TARGET cran
    POST_BUILD
    COMMAND ${R_COMMAND} -q -e \"library\(\'devtools\'\)\;build\(\'R-package\'\)\;\"
)
