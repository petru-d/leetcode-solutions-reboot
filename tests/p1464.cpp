#include "pch.h"

#include "../problems/p1464.h"

TEST(p1464, t0)
{
    std::vector<int> nums = {3, 4, 5, 2};

    p1464::Solution s;
    auto res = s.maxProduct(nums);

    EXPECT_EQ(res, 12);
}