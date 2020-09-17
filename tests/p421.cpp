#include "pch.h"

#include "../problems/p421.h"

TEST(p421, t0)
{
    p421::Solution s;

    std::vector<int> nums = {3, 10, 5, 25, 2, 8};
    auto res = s.findMaximumXOR(nums);

    EXPECT_EQ(res, 28);
}

TEST(p421, t1)
{
    p421::Solution s;

    std::vector<int> nums = {32, 18, 33, 42, 29, 20, 26, 36, 15, 46};
    auto res = s.findMaximumXOR(nums);

    EXPECT_EQ(res, 62);
}
