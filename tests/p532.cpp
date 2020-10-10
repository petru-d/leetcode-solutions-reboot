#include "pch.h"

#include "../problems/p532.h"

TEST(p532, t0)
{
    p532::Solution s;

    std::vector<int> nums = {3, 1, 4, 1, 5};
    auto res = s.findPairs(nums, 2);
    EXPECT_EQ(res, 2);
}
