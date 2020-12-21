
#include <gtest/gtest.h>
#include <ginkgo/ginkgo.hpp>

#include <string>

#include "test/utils.hpp"

#include "../include/hw6.hpp"


template <typename ValueIndexType>
class CsrSpmv : public ::testing::Test {
protected:
    using ValueType =
        typename std::tuple_element<0, decltype(ValueIndexType())>::type;
    using IndexType =
        typename std::tuple_element<1, decltype(ValueIndexType())>::type;
    using CsrMat = gko::matrix::Csr<ValueType, IndexType>;
    using DenseMat = gko::matrix::Dense<ValueType>;

    CsrSpmv()
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
              ref)),
          dense_rhs1(gko::initialize<DenseMat>({1.0, 0.5, 4.0, 0.8}, ref)),
          dense_rhs2(gko::initialize<DenseMat>(
              {
                  // clang-format off
                {1.0, 3.5},
                {0.5, 2,0},
                {4.0, 4.0},
                {0.8, 1.5}
                  // clang-format on
              },
              ref))
    {}

    std::shared_ptr<gko::Executor> ref;
    std::unique_ptr<DenseMat> dense_mat;
    std::unique_ptr<DenseMat> dense_rhs1;
    std::unique_ptr<DenseMat> dense_rhs2;

    template <typename CompType>
    static void assert_equal_vectors(const size_type &num_elems,
                                     const CompType *vec1, const CompType *vec2)
    {
        for (auto i = 0; i < num_elems; ++i) {
            EXPECT_EQ(vec1[i], vec2[i]);
        }
    }
};


TYPED_TEST_CASE(CsrSpmv, gko::test::ValueIndexTypes);


TYPED_TEST(CsrSpmv, SpmvIsCorrectWithSingleRhs)
{
    using ValueType = typename TestFixture::ValueType;
    using IndexType = typename TestFixture::IndexType;
    using CsrMat = typename TestFixture::CsrMat;
    using DenseMat = typename TestFixture::DenseMat;

    auto csr_mat_gko = CsrMat::create(this->ref, this->dense_mat->get_size());
    csr_mat_gko->copy_from(this->dense_mat.get());
    gko::size_type num_rows = this->dense_mat->get_size()[0];
    gko::size_type num_cols = this->dense_mat->get_size()[1];
    auto x = DenseMat::create(this->ref, this->dense_rhs1->get_size());

    csr_mat_gko->apply(gko::lend(this->dense_rhs1), gko::lend(x));
    IndexType row_ptrs[] = {0, 4, 6, 9, 11};
    IndexType col_idxs[] = {0, 1, 2, 3, 1, 3, 0, 2, 3, 1, 3};
    ValueType values[] = {1.0, 2.0,  3.0,  4.0,  9.0,  15.0,
                          4.0, 50.0, 60.0, 54.0, 175.0};

    ValueType xvalues[] = {17.2, 16.5, 252.0, 167.0};

    csr_spmv(this->dense_mat->get_size()[0], this->dense_mat->get_size()[1],
             row_ptrs, col_idxs, this->dense_mat->get_const_values(),
             this->dense_rhs1->get_const_values(), xvalues);

    this->assert_equal_vectors(x->get_num_stored_elements(), xvalues,
                               x->get_values());
}


TYPED_TEST(CsrSpmv, SpmvIsCorrectWithMultipleRhs)
{
    using ValueType = typename TestFixture::ValueType;
    using IndexType = typename TestFixture::IndexType;
    using CsrMat = typename TestFixture::CsrMat;
    using DenseMat = typename TestFixture::DenseMat;

    auto csr_mat_gko = CsrMat::create(this->ref, this->dense_mat->get_size());
    csr_mat_gko->copy_from(this->dense_mat.get());
    gko::size_type num_rows = this->dense_mat->get_size()[0];
    gko::size_type num_cols = this->dense_mat->get_size()[1];
    auto x = DenseMat::create(this->ref, this->dense_rhs2->get_size());

    csr_mat_gko->apply(gko::lend(this->dense_rhs2), gko::lend(x));
    IndexType row_ptrs[] = {0, 4, 6, 9, 11};
    IndexType col_idxs[] = {0, 1, 2, 3, 1, 3, 0, 2, 3, 1, 3};
    ValueType values[] = {1.0, 2.0,  3.0,  4.0,  9.0,  15.0,
                          4.0, 50.0, 60.0, 54.0, 175.0};

    ValueType xvalues[] = {17.2, 25.5, 16.5, 40.5, 252.0, 304.0, 167.0, 370.5};

    csr_spmv(this->dense_mat->get_size()[0], this->dense_mat->get_size()[1],
             row_ptrs, col_idxs, this->dense_mat->get_const_values(),
             this->dense_rhs2->get_const_values(), xvalues);

    this->assert_equal_vectors(x->get_num_stored_elements(), xvalues,
                               x->get_values());
}
