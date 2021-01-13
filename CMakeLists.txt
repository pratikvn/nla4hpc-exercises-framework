cmake_minimum_required(VERSION 3.9)

project(NLA4HPC LANGUAGES C CXX DESCRIPTION "Skeleton code for Numerical Linear Algebra for HPC course at KIT")

include(cmake/build_type_helpers.cmake)

# Configuration options
option(NLA4HPC_BUILD_TESTS "Generate build files for unit tests" ON)
set(NLA4HPC_CUDA_ARCHITECTURES "Auto" CACHE STRING
    "A list of target NVIDIA GPU achitectures. See README.md for more detail.")
option(NLA4HPC_DEVEL_TOOLS "Install support for some developer tools" OFF)
OPTION(NLA4HPC_GENERATE_BENCHMARK "Build benchmarks using Google benchmark suite" OFF)
set(NLA4HPC_HW "0" CACHE STRING
  "Set the HW you want to build as a number, default: 0")
set(NLA4HPC_KIT_UNAME "uxxxx0" CACHE STRING
  "Set your KIT username, uxxxx0, default: uxxxx0")
option(NLA4HPC_SKIP_DEPENDENCY_UPDATE
  "Do not update dependencies each time the project is rebuilt" ON)

# use external ginkgo whenever possible.
set(NLA4HPC_USE_EXTERNAL_GINKGO 1)

if(NLA4HPC_BUILD_TESTS)
  # Configure CTest
  configure_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/CTestCustom.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/CTestCustom.cmake @ONLY)

  enable_testing()
  include(CTest)
endif()

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Find important header files, store the definitions in include/ginkgo/config.h.in
# For details, see https://gitlab.kitware.com/cmake/community/wikis/doc/tutorials/How-To-Write-Platform-Checks
include(CheckIncludeFileCXX)
check_include_file_cxx(cxxabi.h GKO_HAVE_CXXABI_H)

# Load CMake helpers
include(cmake/package_helpers.cmake)
include(cmake/build_helpers.cmake)
include(cmake/install_helpers.cmake)

# Try to find the third party packages before using our subdirectories
ginkgo_find_package(GTest "GTest::GTest;GTest::Main" FALSE 1.8.1)
ginkgo_find_package(GBenchmark "GBenchmark::GBenchmark;GBenchmark::Main" FALSE)
ginkgo_find_package(Ginkgo "Ginkgo::ginkgo" FALSE 1.2.0)

add_subdirectory(third_party)
if (NOT Ginkgo)
  find_package(Ginkgo 1.2.0 REQUIRED PATHS ${CMAKE_CURRENT_BINARY_DIR}/third_party/ginkgo/build/install/lib/cmake)
endif()

set(hwstring "hw${NLA4HPC_HW}")
add_subdirectory("${hwstring}")
