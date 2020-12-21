
#include <gtest/gtest.h>
#include <ginkgo/ginkgo.hpp>

#include <string>

#include "test/utils.hpp"

#include "hw1/uxxxx0/include/hw1.hpp"


template <typename T>
class Dense : public ::testing::Test {
protected:
    using value_type = T;
    using Vec = gko::matrix::Dense<value_type>;
    using RealVec = gko::matrix::Dense<gko::remove_complex<value_type>>;
    using Mat = gko::matrix::Dense<value_type>;
    Dense()
        : exec(gko::ReferenceExecutor::create()),
          vec1(gko::initialize<Vec>({4.0, 2.0, 0.0, -1.0}, exec)),
          vec2(gko::initialize<Vec>({1.0, -2.0, 9.0, -2.0}, exec)),
          mat1(gko::initialize<Mat>(
              {{1.0, -2.0, 3.0, 0.0}, {-1.0, -2.5, 9.0, -2.0}}, exec)),
          mat2(gko::initialize<Mat>({{4.0, 2.5}, {0.0, -2.0}, {0.0, -2.0}},
                                    exec)),
          mat3(gko::initialize<Mat>({{2.0, -5.5, 3.0}, {0.5, 2.0, 9.0}}, exec))
    {}

    std::shared_ptr<const gko::Executor> exec;
    std::unique_ptr<Vec> vec1;
    std::unique_ptr<Vec> vec2;
    std::unique_ptr<Mat> mat1;
    std::unique_ptr<Mat> mat2;
    std::unique_ptr<Mat> mat3;

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


TYPED_TEST(Dense, ComputesCorrectNorm2)
{
    using value_type = typename TestFixture::value_type;
    using Vec = typename TestFixture::Vec;
    using RealVec = typename TestFixture::RealVec;
    auto comp_res = Vec::create(this->exec, gko::dim<2>{1, 1});
    this->vec1->compute_norm2(comp_res.get());

    value_type res = 0.0;
    norm2(this->vec1->get_const_values(), this->vec1->get_size()[0], res);

    ASSERT_EQ(res, comp_res->at(0));
}


TYPED_TEST(Dense, ComputesCorrectMatVec)
{
    using value_type = typename TestFixture::value_type;
    using Vec = typename TestFixture::Vec;

    auto base_vec = gko::initialize<Vec>({1.0, -2.0}, this->exec);
    auto comp_vec = Vec::create(this->exec, base_vec->get_size());
    comp_vec->copy_from(base_vec.get());
    auto one = gko::initialize<Vec>({1.0}, this->exec);

    this->mat1->apply(one.get(), this->vec1.get(), one.get(), base_vec.get());
    mat_vec(this->mat1->get_const_values(), this->mat1->get_size()[0],
            this->mat1->get_size()[1], this->vec1->get_const_values(),
            this->vec1->get_size()[0], comp_vec->get_values());

    this->assert_equal_matrices(comp_vec.get(), base_vec.get());
}


TYPED_TEST(Dense, ComputesCorrectMatMult)
{
    using value_type = typename TestFixture::value_type;
    using Vec = typename TestFixture::Vec;

    auto base_mat = gko::initialize<Vec>(
        {{1.0, -2.0, 1.0}, {3.0, 2.5, -8.5}, {-3.5, 0.7, 1.5}}, this->exec);
    auto comp_mat = Vec::create(this->exec, base_mat->get_size());
    comp_mat->copy_from(base_mat.get());
    auto one = gko::initialize<Vec>({1.0}, this->exec);

    this->mat2->apply(one.get(), this->mat3.get(), one.get(), base_mat.get());
    mat_mult(this->mat2->get_const_values(), this->mat2->get_size()[0],
             this->mat2->get_size()[1], this->mat3->get_const_values(),
             this->mat3->get_size()[0], this->mat3->get_size()[1],
             comp_mat->get_values(), comp_mat->get_size()[0],
             comp_mat->get_size()[1]);

    this->assert_equal_matrices(comp_mat.get(), base_mat.get());
}
