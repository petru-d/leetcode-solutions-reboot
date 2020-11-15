#include "pch.h"

#include "../problems/p1283.h"

TEST(p1283, t0)
{
    p1283::Solution s;

    std::vector<int> nums = {1, 2, 5, 9};
    auto res = s.smallestDivisor(nums, 6);

    EXPECT_EQ(res, 5);
}
