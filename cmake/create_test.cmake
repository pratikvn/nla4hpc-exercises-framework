function(ginkgo_create_test test_name)
  file(RELATIVE_PATH REL_BINARY_DIR
    ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  string(REPLACE "/" "_" TEST_TARGET_NAME "${REL_BINARY_DIR}/${test_name}")
  add_executable(${TEST_TARGET_NAME} ${test_name}.cpp)
  target_compile_features("${TEST_TARGET_NAME}" PUBLIC cxx_std_14)
  target_include_directories("${TEST_TARGET_NAME}"
    PRIVATE
    "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
    )
  set_target_properties(${TEST_TARGET_NAME} PROPERTIES
    OUTPUT_NAME ${test_name})
  if (GINKGO_CHECK_CIRCULAR_DEPS)
    target_link_libraries(${TEST_TARGET_NAME} PRIVATE "${GINKGO_CIRCULAR_DEPS_FLAGS}")
  endif()
  target_link_libraries(${TEST_TARGET_NAME} PUBLIC Ginkgo::ginkgo GTest::Main GTest::GTest ${ARGN})
  add_test(NAME ${REL_BINARY_DIR}/${test_name} COMMAND ${TEST_TARGET_NAME})
endfunction(ginkgo_create_test)

function(ginkgo_create_gbench bench_name)
  find_package(Threads REQUIRED)
  file(RELATIVE_PATH REL_BINARY_DIR
    ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  string(REPLACE "/" "_" TEST_TARGET_NAME "${REL_BINARY_DIR}/${bench_name}")
  add_executable(${TEST_TARGET_NAME} ${bench_name}.cpp)
  target_compile_features("${TEST_TARGET_NAME}" PUBLIC cxx_std_14)
  target_include_directories("${TEST_TARGET_NAME}"
    PRIVATE
    "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>"
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
    )
  set_target_properties(${TEST_TARGET_NAME} PROPERTIES
    OUTPUT_NAME ${bench_name})
  if (GINKGO_CHECK_CIRCULAR_DEPS)
    target_link_libraries(${TEST_TARGET_NAME} PRIVATE "${GINKGO_CIRCULAR_DEPS_FLAGS}")
  endif()
  target_link_libraries(${TEST_TARGET_NAME} PUBLIC Ginkgo::ginkgo GTest::Main GTest::GTest GBenchmark::GBenchmark Threads::Threads ${ARGN})
  add_test(NAME ${REL_BINARY_DIR}/${bench_name} COMMAND ${TEST_TARGET_NAME})
endfunction(ginkgo_create_gbench)

function(ginkgo_create_thread_test test_name)
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)
  file(RELATIVE_PATH REL_BINARY_DIR
    ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  string(REPLACE "/" "_" TEST_TARGET_NAME "${REL_BINARY_DIR}/${test_name}")
  add_executable(${TEST_TARGET_NAME} ${test_name}.cpp)
  target_compile_features("${TEST_TARGET_NAME}" PUBLIC cxx_std_14)
  target_include_directories("${TEST_TARGET_NAME}"
    PRIVATE
    "$<BUILD_INTERFACE:${Ginkgo_BINARY_DIR}>"
    )
  set_target_properties(${TEST_TARGET_NAME} PROPERTIES
    OUTPUT_NAME ${test_name})
  if (GINKGO_CHECK_CIRCULAR_DEPS)
    target_link_libraries(${TEST_TARGET_NAME} PRIVATE "${GINKGO_CIRCULAR_DEPS_FLAGS}")
  endif()
  target_link_libraries(${TEST_TARGET_NAME} PRIVATE Ginkgo::ginkgo GTest::Main GTest::GTest Threads::Threads ${ARGN})
  add_test(NAME ${REL_BINARY_DIR}/${test_name} COMMAND ${TEST_TARGET_NAME})
endfunction(ginkgo_create_thread_test)

function(ginkgo_create_test_cpp_cuda_header test_name)
  file(RELATIVE_PATH REL_BINARY_DIR
    ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  string(REPLACE "/" "_" TEST_TARGET_NAME "${REL_BINARY_DIR}/${test_name}")
  add_executable(${TEST_TARGET_NAME} ${test_name}.cpp)
  target_compile_features("${TEST_TARGET_NAME}" PUBLIC cxx_std_14)
  target_include_directories("${TEST_TARGET_NAME}"
    PRIVATE
    "$<BUILD_INTERFACE:${Ginkgo_BINARY_DIR}>"
    "${CUDA_INCLUDE_DIRS}"
    )
  set_target_properties(${TEST_TARGET_NAME} PROPERTIES
    OUTPUT_NAME ${test_name})
  if (GINKGO_CHECK_CIRCULAR_DEPS)
    target_link_libraries(${TEST_TARGET_NAME} PRIVATE "${GINKGO_CIRCULAR_DEPS_FLAGS}")
  endif()
  target_link_libraries(${TEST_TARGET_NAME} PRIVATE Ginkgo::ginkgo GTest::Main GTest::GTest ${ARGN})
  add_test(NAME ${REL_BINARY_DIR}/${test_name} COMMAND ${TEST_TARGET_NAME})
endfunction(ginkgo_create_test_cpp_cuda_header)

function(ginkgo_create_cuda_test test_name)
  file(RELATIVE_PATH REL_BINARY_DIR
    ${PROJECT_BINARY_DIR} ${CMAKE_CURRENT_BINARY_DIR})
  string(REPLACE "/" "_" TEST_TARGET_NAME "${REL_BINARY_DIR}/${test_name}")
  add_executable(${TEST_TARGET_NAME} ${test_name}.cu)
  target_compile_features("${TEST_TARGET_NAME}" PUBLIC cxx_std_14)
  target_include_directories("${TEST_TARGET_NAME}"
    PRIVATE
    "$<BUILD_INTERFACE:${Ginkgo_BINARY_DIR}>"
    )
 cas_target_cuda_architectures(${TEST_TARGET_NAME}
    ARCHITECTURES ${GINKGO_CUDA_ARCHITECTURES}
    UNSUPPORTED "20" "21")
  set_target_properties(${TEST_TARGET_NAME} PROPERTIES
    OUTPUT_NAME ${test_name})

  if (GINKGO_CHECK_CIRCULAR_DEPS)
    target_link_libraries(${TEST_TARGET_NAME} PRIVATE "${GINKGO_CIRCULAR_DEPS_FLAGS}")
  endif()
  target_link_libraries(${TEST_TARGET_NAME} PRIVATE Ginkgo::ginkgo GTest::Main GTest::GTest ${ARGN})
  add_test(NAME ${REL_BINARY_DIR}/${test_name} COMMAND ${TEST_TARGET_NAME})
endfunction(ginkgo_create_cuda_test)
