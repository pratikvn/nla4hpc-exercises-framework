set(target_name hw3)
add_library(${target_name} SHARED "")
target_sources(${target_name}
  PRIVATE
  src/hw3.cpp)
target_link_libraries(${target_name} Ginkgo::ginkgo)
target_include_directories(${target_name} PRIVATE ${PROJECT_SOURCE_DIR})

include(${PROJECT_SOURCE_DIR}/cmake/create_test.cmake)

if(NLA4HPC_BUILD_TESTS)
  add_subdirectory(tests)
endif()
