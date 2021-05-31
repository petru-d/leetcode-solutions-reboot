#include "pch.h"

#include "../problems/p1695.h"

TEST(p1695, t0)
{
    std::vector<int> nums = {5, 2, 1, 2, 5, 2, 1, 2, 5};
    p1695::Solution s;
    auto res = s.maximumUniqueSubarray(nums);
    EXPECT_EQ(res, 8);
}
