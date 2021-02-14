#include "pch.h"

#include "../problems/p1658.h"

TEST(p1658, t0)
{
    p1658::Solution s;

    std::vector<int> nums = {1, 1, 4, 2, 3};

    auto res = s.minOperations(nums, 5);

    EXPECT_EQ(res, 2);
}
