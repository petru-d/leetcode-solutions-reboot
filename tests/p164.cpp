#include "pch.h"

#include "../problems/p164.h"

TEST(p164, t0)
{
    std::vector<int> nums = {3, 6, 9, 1};

    p164::Solution s;
    auto res = s.maximumGap(nums);
    EXPECT_EQ(res, 3);

    p164::Solution2 s2;
    auto res2 = s2.maximumGap(nums);
    EXPECT_EQ(res2, 3);
}

TEST(p164, t1)
{
    std::vector<int> nums = {1, 1, 1, 1, 1, 5, 5, 5, 5, 5};

    p164::Solution s;
    auto res = s.maximumGap(nums);
    EXPECT_EQ(res, 4);

    p164::Solution2 s2;
    auto res2 = s2.maximumGap(nums);
    EXPECT_EQ(res2, 4);
}
