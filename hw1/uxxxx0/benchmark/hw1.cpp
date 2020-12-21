#include <cmath>
#include <ginkgo/ginkgo.hpp>
#include <random>
#include "benchmark/benchmark.h"
#include "test/utils.hpp"

#include "hw1/uxxxx0/include/hw1.hpp"

#define VEC_LEN 20
#define MAT_LEN 10

template <typename ValueType>
static void bench_norm2(benchmark::State &st)
{
    using Vec = gko::matrix::Dense<ValueType>;
    auto exec = gko::ReferenceExecutor::create();

    size_type nelems = std::pow(2, st.range(0));

    auto vec = gko::test::generate_random_matrix<Vec>(
        nelems, 1,
        std::normal_distribution<gko::remove_complex<ValueType>>(50, 5),
        std::normal_distribution<gko::remove_complex<ValueType>>(50, 5),
        std::ranlux48(42), exec);

    gko::remove_complex<ValueType> res = 0.0;
    for (auto _ : st) {
        // TODO call norm2 here
    }
}

BENCHMARK_TEMPLATE(bench_norm2, float)->DenseRange(1, VEC_LEN);
BENCHMARK_TEMPLATE(bench_norm2, double)->DenseRange(1, VEC_LEN);
BENCHMARK_TEMPLATE(bench_norm2, std::complex<float>)->DenseRange(1, VEC_LEN);
BENCHMARK_TEMPLATE(bench_norm2, std::complex<double>)->DenseRange(1, VEC_LEN);

template <typename ValueType>
static void bench_mat_vec(benchmark::State &st)
{
    // TODO implement this
}

BENCHMARK_TEMPLATE(bench_mat_vec, float)->DenseRange(1, MAT_LEN);
BENCHMARK_TEMPLATE(bench_mat_vec, double)->DenseRange(1, MAT_LEN);

template <typename ValueType>
static void bench_mat_mult(benchmark::State &st)
{
    // TODO implement this
}

BENCHMARK_TEMPLATE(bench_mat_mult, float)->DenseRange(1, MAT_LEN);
BENCHMARK_TEMPLATE(bench_mat_mult, double)->DenseRange(1, MAT_LEN);

BENCHMARK_MAIN();
