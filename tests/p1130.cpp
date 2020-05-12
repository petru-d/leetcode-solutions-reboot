#include "pch.h"

#include "../problems/p1130.h"

TEST(p1130, t0)
{
    std::vector<int> nums = {6, 2, 4};

    p1130::Solution s;
    auto res = s.mctFromLeafValues(nums);
    EXPECT_EQ(res, 32);
}

TEST(p1130, t1)
{
    std::vector<int> nums = {6, 4, 2};

    p1130::Solution s;
    auto res = s.mctFromLeafValues(nums);
    EXPECT_EQ(res, 32);
}
