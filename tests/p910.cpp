#include "pch.h"

#include "../problems/p910.h"

TEST(p910, t0)
{
    p910::Solution s;

    std::vector<int> nums = {0, 10};
    auto res = s.smallestRangeII(nums, 2);

    EXPECT_EQ(res, 6);
}
