#include "pch.h"

#include "../problems/p75.h"

TEST(p75, t0)
{
    p75::Solution s;

    std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    s.sortColors(nums);

    std::vector<int> exp = {0, 0, 1, 1, 2, 2};
    EXPECT_EQ(nums, exp);
}
