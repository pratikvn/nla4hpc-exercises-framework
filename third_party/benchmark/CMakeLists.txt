ginkgo_load_git_package(gbench
        "https://github.com/google/benchmark.git"
        "73d4d5e8d6d449fc8663765a42aa8aeeee844489"
        "-DCMAKE_CXX_FLAGS=-fPIC" "-DCMAKE_INSTALL_PREFIX=install"
        "-DBENCHMARK_ENABLE_TESTING=OFF"
        )

ginkgo_add_external_target(GBenchmark::GBenchmark benchmark build/install/include build/install/lib
   STATIC "" gbench FALSE)
ginkgo_add_external_target(GBenchmark::Main benchmark_main build/install/include build/install/lib
   STATIC "" gbench_external FALSE)
