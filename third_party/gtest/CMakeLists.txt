if(MSVC)
    # Force using shared runtime library when MSVC builds shared libraries
    ginkgo_load_git_package(gtest_external
        "https://github.com/google/googletest.git"
        "df428ec11891f12c81e2872c0432e342b5403a34"
        # Work around the linking errors when compiling gtest with CUDA
        "-Dgtest_disable_pthreads=ON" "-Dgtest_force_shared_crt=${BUILD_SHARED_LIBS}"
        "-DCMAKE_INSTALL_PREFIX=build/googlemock/gtest")
else()
    ginkgo_load_git_package(gtest_external
        "https://github.com/google/googletest.git"
        "df428ec11891f12c81e2872c0432e342b5403a34"
        # Work around the linking errors when compiling gtest with CUDA
        "-Dgtest_disable_pthreads=ON"
        "-DCMAKE_CXX_FLAGS=-fPIC" "-DCMAKE_INSTALL_PREFIX=install")
endif()

ginkgo_add_external_target(GTest::GTest gtest build/install/include build/install/lib
    STATIC "d" gtest_external FALSE)
ginkgo_add_external_target(GTest::Main gtest_main build/install/include build/install/lib
    STATIC "d" gtest_external FALSE)
