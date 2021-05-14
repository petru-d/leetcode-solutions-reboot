#include "pch.h"

#include "../problems/p1480.h"

TEST(p1480, t0)
{
    p1480::Solution s;

    std::vector<int> nums = {1, 2, 3};
    auto res = s.runningSum(nums);
    EXPECT_EQ(res, (std::vector<int>{1, 3, 6}));
}
