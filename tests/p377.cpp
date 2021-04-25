#include "pch.h"

#include "../problems/p377.h"

TEST(p377, t0)
{
    p377::Solution s;

    std::vector<int> nums = {1, 2, 3};
    auto res = s.combinationSum4(nums, 4);
    EXPECT_EQ(res, 7);
}
