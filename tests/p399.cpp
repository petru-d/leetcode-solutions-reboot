#include "pch.h"

#include "../problems/p399.h"

TEST(p399, t0)
{
    p399::Solution s;

    std::vector<std::vector<std::string>> equations = {{"a", "b"}, {"b", "c"}};
    std::vector<double> values = {2., 3.};
    std::vector<std::vector<std::string>> querries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    auto res = s.calcEquation(equations, values, querries);

    std::vector<double> expected = {6., 0.5, -1.0, 1., -1.};

    ASSERT_EQ(res.size(), expected.size());

    for (size_t i = 0; i < res.size(); ++i)
    {
        EXPECT_NEAR(res[i], expected[i], 0.0000001);
    }
}

TEST(p399, t1)
{
    p399::Solution s;

    std::vector<std::vector<std::string>> equations = {{"a", "b"}, {"b", "c"}, {"bc", "cd"}};
    std::vector<double> values = {1.5, 2.5, 5.};
    std::vector<std::vector<std::string>> querries = {{"a", "c"}, {"c", "b"}, {"bc", "cd"}, {"cd", "bc"}};

    auto res = s.calcEquation(equations, values, querries);

    std::vector<double> expected = {3.75, 0.4, 5., 0.2};

    ASSERT_EQ(res.size(), expected.size());

    for (size_t i = 0; i < res.size(); ++i)
    {
        EXPECT_NEAR(res[i], expected[i], 0.0000001);
    }
}

TEST(p399, t2)
{
    p399::Solution s;

    std::vector<std::vector<std::string>> equations = {{"a", "b"}};
    std::vector<double> values = {0.5};
    std::vector<std::vector<std::string>> querries = {{"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};

    auto res = s.calcEquation(equations, values, querries);

    std::vector<double> expected = {0.5, 2., -1., -1.};

    ASSERT_EQ(res.size(), expected.size());

    for (size_t i = 0; i < res.size(); ++i)
    {
        EXPECT_NEAR(res[i], expected[i], 0.0000001);
    }
}