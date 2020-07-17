#include "pch.h"

#include "../problems/p152.h"

TEST(p152, t0)
{
    p152::Solution s;

    std::vector<int> nums = {2, 3, -2, 4};
    auto p = s.maxProduct(nums);

    EXPECT_EQ(p, 6);
}

TEST(p152, t1)
{
    p152::Solution s;

    std::vector<int> nums = {-2, 0, -1};
    auto p = s.maxProduct(nums);

    EXPECT_EQ(p, 0);
}

TEST(p152, t2)
{
    p152::Solution s;

    std::vector<int> nums = {0};
    auto p = s.maxProduct(nums);

    EXPECT_EQ(p, 0);
}

TEST(p152, t3)
{
    p152::Solution s;

    std::vector<int> nums = {3, -1, 4};
    auto p = s.maxProduct(nums);

    EXPECT_EQ(p, 4);
}

TEST(p152, t4)
{
    p152::Solution s;

    std::vector<int> nums = {1, 0, -1, 2, 3, -5, -2};
    auto p = s.maxProduct(nums);

    EXPECT_EQ(p, 60);
}
