#include "pch.h"

#include "../problems/p164.h"

TEST(p164, t0)
{
    p164::Solution s;

    std::vector<int> nums = {3, 6, 9, 1};

    auto res = s.maximumGap(nums);

    EXPECT_EQ(res, 3);
}

TEST(p164, t1)
{
    p164::Solution s;

    std::vector<int> nums = {1, 1, 1, 1, 1, 5, 5, 5, 5, 5};

    auto res = s.maximumGap(nums);

    EXPECT_EQ(res, 4);
}
