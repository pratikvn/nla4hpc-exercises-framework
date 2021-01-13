set(target_name hw6)
add_library(${target_name} SHARED "")

include(CudaArchitectureSelector)
enable_language(CUDA)

set(CUDA_INCLUDE_DIRS ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})

set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS}" PARENT_SCOPE)
set(CMAKE_CUDA_COMPILER_VERSION ${CMAKE_CUDA_COMPILER_VERSION} PARENT_SCOPE)
set(CUDA_INCLUDE_DIRS ${CUDA_INCLUDE_DIRS} PARENT_SCOPE)

find_library(CUDA_RUNTIME_LIBS_DYNAMIC cudart
        HINT ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})
find_library(CUBLAS cublas
    HINT ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES} NO_DEFAULT_PATH)
find_library(CUSPARSE cusparse
    HINT ${CMAKE_CUDA_IMPLICIT_LINK_DIRECTORIES})

# Directly add .cu files to be compiled with CUDA here.
target_sources(${target_name}
  PRIVATE
  src/hw6.cpp)
target_link_libraries(${target_name} Ginkgo::ginkgo)
target_link_libraries(${target_name} ${CUDA_RUNTIME_LIBS_DYNAMIC} ${CUBLAS} ${CUSPARSE})
target_include_directories(${target_name} PRIVATE ${PROJECT_SOURCE_DIR})

cas_target_cuda_architectures(${target_name}
    ARCHITECTURES ${NLA4HPC_CUDA_ARCHITECTURES}
    UNSUPPORTED "20" "21")

include(${PROJECT_SOURCE_DIR}/cmake/create_test.cmake)

if(NLA4HPC_BUILD_TESTS)
  add_subdirectory(tests)
endif()
