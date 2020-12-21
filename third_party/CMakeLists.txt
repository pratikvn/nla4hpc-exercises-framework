if(GINKGO_BUILD_CUDA)
    enable_language(CUDA)
    add_subdirectory(CudaArchitectureSelector)
endif()

# For each external package, check if they are already available, otherwise use ours
if(NLA4HPC_BUILD_TESTS)
    ginkgo_add_subdirectory(GTest gtest)
endif()

if(NLA4HPC_GENERATE_BENCHMARK)
  ginkgo_add_subdirectory(GBench benchmark)
endif()

if(NLA4HPC_DEVEL_TOOLS)
    set(GCF_IGNORE_LIST "third_party" CACHE STRING "Ignore directories for GCF")
    add_subdirectory(git-cmake-format)
else()
    add_subdirectory(dummy-hook)
endif()

ginkgo_add_subdirectory(Ginkgo ginkgo)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" PARENT_SCOPE)
