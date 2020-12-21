
#include <gtest/gtest.h>
#include <ginkgo/ginkgo.hpp>

#include <string>

#include "test/utils.hpp"

#include "../include/hw3.hpp"


template <typename T>
class Dense : public ::testing::Test {
protected:
    using value_type = T;
    using Mat = gko::matrix::Dense<value_type>;
    Dense()
        : exec(gko::ReferenceExecutor::create()),
          mat1(gko::initialize<Mat>(
              {
                  // clang-format off
                {1.0, 2.0, 3.0, 4.0},
                {2.0, 9.0, 12.0, 15.0},
                {4.0, 33.0, 50.0, 60.0},
                {7.0, 54.0, 141.0, 175.0}
                  // clang-format on
              },
              exec)),
          lfac(gko::initialize<Mat>(
              {
                  // clang-format off
                {1.0, 0.0, 0.0, 0.0},
                {2.0, 1.0, 0.0, 0.0},
                {4.0, 5.0, 1.0, 0.0},
                {7.0, 8.0, 9.0, 1.0}
                  // clang-format on
              },
              exec)),
          ufac(gko::initialize<Mat>(
              {
                  // clang-format off
                {1.0, 2.0, 3.0, 4.0},
                {0.0, 5.0, 6.0, 7.0},
                {0.0, 0.0, 8.0, 9.0},
                {0.0, 0.0, 0.0, 10.0}
                  // clang-format on
              },
              exec))
    {}

    std::shared_ptr<const gko::Executor> exec;
    std::unique_ptr<Mat> mat1;
    std::unique_ptr<Mat> mat2;
    std::unique_ptr<Mat> lfac;
    std::unique_ptr<Mat> ufac;

    void assert_equal_matrices(const Mat *mat_1, const Mat *mat_2)
    {
        ASSERT_EQ(mat_1->get_size(), mat_2->get_size());
        ASSERT_EQ(mat_1->get_stride(), mat_2->get_stride());
        ASSERT_EQ(mat_1->get_num_stored_elements(),
                  mat_2->get_num_stored_elements());
        for (size_type i = 0; i < mat_1->get_num_stored_elements(); ++i)
            EXPECT_EQ(mat_1->get_const_values()[i],
                      mat_2->get_const_values()[i]);
    }
};

TYPED_TEST_CASE(Dense, gko::test::RealValueTypes);


TYPED_TEST(Dense, ComputesCorrectLUFactorsWithoutPivoting)
{
    using value_type = typename TestFixture::value_type;
    using Mat = typename TestFixture::Mat;

    auto mat_l = Mat::create(this->exec, this->mat1->get_size());
    auto mat_u = Mat::create(this->exec, this->mat1->get_size());

    compute_lu_factorization(this->mat1->get_const_values(),
                             this->mat1->get_size()[0], mat_l->get_values(),
                             mat_u->get_values());

    auto lu = Mat::create(this->exec, this->mat1->get_size());
    mat_l->apply(mat_u.get(), lu.get());

    GKO_ASSERT_MTX_NEAR(this->mat1.get(), lu.get(), 1e-7);
    GKO_ASSERT_MTX_NEAR(this->lfac.get(), mat_l.get(), 1e-7);
    GKO_ASSERT_MTX_NEAR(this->ufac.get(), mat_u.get(), 1e-7);
}


// Add a test for LU factorization with pivoting.
