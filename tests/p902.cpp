#include "pch.h"

#include "../problems/p902.h"

TEST(p902, t0)
{
    p902::Solution s;

    std::vector<std::string> d = {"1", "3", "5", "7"};
    auto res = s.atMostNGivenDigitSet(d, 100);

    EXPECT_EQ(res, 20);
}

TEST(p902, t1)
{
    p902::Solution s;

    std::vector<std::string> d = {"1", "4", "9"};
    auto res = s.atMostNGivenDigitSet(d, 1000000000);

    EXPECT_EQ(res, 29523);
}

TEST(p902, t2)
{
    p902::Solution s;

    std::vector<std::string> d = {"7"};
    auto res = s.atMostNGivenDigitSet(d, 8);

    EXPECT_EQ(res, 1);
}
