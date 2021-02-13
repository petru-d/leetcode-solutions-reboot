#include "pch.h"

#include "../problems/p300.h"

TEST(p300, t0)
{
    [[maybe_unused]] p300::Solution s;

    std::vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    auto res = s.lengthOfLIS(nums);
    EXPECT_EQ(res, 4);

    res = s.lengthOfLIS2(nums);
    EXPECT_EQ(res, 4);
}
