#include "pch.h"

#include "../problems/p851.h"

TEST(p851, t0)
{
    p851::Solution s;

    std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    auto res = s.findUnsortedSubarray_leetcode(nums);
    EXPECT_EQ(res, 5);
    res = s.findUnsortedSubarray_mine(nums);
    EXPECT_EQ(res, 5);
}
