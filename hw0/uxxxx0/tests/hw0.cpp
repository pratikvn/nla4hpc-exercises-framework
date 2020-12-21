
#include <gtest/gtest.h>
#include <ginkgo/ginkgo.hpp>

#include <string>

#include "test/utils.hpp"

#include "hw0/uxxxx0/include/hw0.hpp"

template <typename T>
class Dense : public ::testing::Test {
protected:
    using value_type = T;
    using Vec = gko::matrix::Dense<value_type>;
    Dense()
        : exec(gko::ReferenceExecutor::create()),
          vec1(gko::initialize<Vec>({4.0, 2.0, 0.0, -1.0}, exec)),
          vec2(gko::initialize<Vec>({1.0, -2.0, 9.0, -2.0}, exec))
    {}

    std::shared_ptr<const gko::Executor> exec;
    std::unique_ptr<Vec> vec1;
    std::unique_ptr<Vec> vec2;

    void assert_equal_vectors(const Vec *vec_1, const Vec *vec_2)
    {
        ASSERT_EQ(vec_1->get_size(), vec_2->get_size());
        for (size_type i = 0; i < vec_1->get_size()[0]; ++i)
            EXPECT_EQ(vec_1->at(i), vec_2->at(i));
    }
};

TYPED_TEST_CASE(Dense, gko::test::ValueTypes);


TYPED_TEST(Dense, ComputesCorrectDot)
{
    using value_type = typename TestFixture::value_type;
    using Vec = typename TestFixture::Vec;
    auto comp_res = Vec::create(this->exec, gko::dim<2>{1, 1});
    this->vec1->compute_dot(this->vec2.get(), comp_res.get());

    value_type res = 0.0;
    dot(this->vec1->get_const_values(), this->vec2->get_const_values(),
        this->vec1->get_size()[0], res);

    ASSERT_EQ(res, comp_res->at(0));
}


TYPED_TEST(Dense, ComputesCorrectAxpy)
{
    using value_type = typename TestFixture::value_type;
    using Vec = typename TestFixture::Vec;
    auto comp_res = Vec::create(this->exec, gko::dim<2>{1, 1});
    auto alpha = gko::initialize<Vec>({-2.0}, this->exec);
    auto comp_vec = Vec::create(this->exec, this->vec1->get_size());
    comp_vec->copy_from(this->vec1.get());

    this->vec1->add_scaled(alpha.get(), this->vec2.get());
    axpy(alpha->get_const_values(), this->vec2->get_const_values(),
         this->vec1->get_size()[0], comp_vec->get_values());

    this->assert_equal_vectors(comp_vec.get(), this->vec1.get());
}
