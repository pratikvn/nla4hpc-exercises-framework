
#include <gtest/gtest.h>
#include <ginkgo/ginkgo.hpp>

#include <string>

#include "test/utils.hpp"

#include "../include/hw5.hpp"


template <typename ValueIndexType>
class DenseToCSR : public ::testing::Test {
protected:
    using ValueType =
        typename std::tuple_element<0, decltype(ValueIndexType())>::type;
    using IndexType =
        typename std::tuple_element<1, decltype(ValueIndexType())>::type;
    using CsrMat = gko::matrix::Csr<ValueType, IndexType>;
    using DenseMat = gko::matrix::Dense<ValueType>;

    DenseToCSR()
        : ref(gko::ReferenceExecutor::create()),
          dense_mat(gko::initialize<DenseMat>(
              {
                  // clang-format off
                {1.0, 2.0, 3.0, 4.0},
                {0.0, 9.0, 0.0, 15.0},
                {4.0, 0.0, 50.0, 60.0},
                {0.0, 54.0, 0.0, 175.0}
                  // clang-format on
              },
              ref))
    {}

    std::shared_ptr<gko::Executor> ref;
    std::unique_ptr<DenseMat> dense_mat;

    template <typename CompType>
    static void assert_equal_arrays(size_type len, const CompType *arr1,
                                    const CompType *arr2)
    {
        for (auto i = 0; i < len; ++i) {
            ASSERT_EQ(arr1[i], arr2[i]);
        }
    }
};


TYPED_TEST_CASE(DenseToCSR, gko::test::ValueIndexTypes);


TYPED_TEST(DenseToCSR, ConvertsDenseToCsr)
{
    using ValueType = typename TestFixture::ValueType;
    using IndexType = typename TestFixture::IndexType;
    using CsrMat = typename TestFixture::CsrMat;

    auto csr_mat_gko = CsrMat::create(this->ref, this->dense_mat->get_size());
    csr_mat_gko->copy_from(this->dense_mat.get());
    gko::size_type num_nnz = csr_mat_gko->get_num_stored_elements();
    gko::size_type num_rows = csr_mat_gko->get_size()[0];
    // An example of how the CSR matrix will look like.
    // You are free to create your own CSR matrix class and compare it with
    // Ginkgo's CSR classes

    IndexType row_ptrs[] = {0, 4, 6, 9, 11};
    IndexType col_idxs[] = {0, 1, 2, 3, 1, 3, 0, 2, 3, 1, 3};
    ValueType values[] = {1.0, 2.0,  3.0,  4.0,  9.0,  15.0,
                          4.0, 50.0, 60.0, 54.0, 175.0};

    convert_dense_to_csr(
        this->dense_mat->get_size()[0], this->dense_mat->get_size()[1],
        this->dense_mat->get_const_values(), row_ptrs, col_idxs, values);

    this->assert_equal_arrays(num_rows + 1, row_ptrs,
                              csr_mat_gko->get_row_ptrs());
    this->assert_equal_arrays(num_nnz, col_idxs, csr_mat_gko->get_col_idxs());
    this->assert_equal_arrays(num_nnz, values, csr_mat_gko->get_values());
}
