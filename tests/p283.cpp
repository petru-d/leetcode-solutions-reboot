#include "pch.h"

#include "../problems/p283.h"

TEST(P283, T0)
{
    p283::Solution s;

    std::vector<int> nums = {0, 1, 0, 3, 12};
    s.moveZeroes(nums);
    std::vector<int> expected = {1, 3, 12, 0, 0};
    EXPECT_EQ(nums, expected);
}

TEST(P283, T1)
{
    p283::Solution s;

    std::vector<int> nums = {};
    s.moveZeroes(nums);
    std::vector<int> expected = {};
    EXPECT_EQ(nums, expected);
}

TEST(P283, T2)
{
    p283::Solution s;

    std::vector<int> nums = {0, 0, 0, 0};
    s.moveZeroes(nums);
    std::vector<int> expected = {0, 0, 0, 0};
    EXPECT_EQ(nums, expected);
}

TEST(P283, T3)
{
    p283::Solution s;

    std::vector<int> nums = {1, 2, 3, 4};
    s.moveZeroes(nums);
    std::vector<int> expected = {1, 2, 3, 4};
    EXPECT_EQ(nums, expected);
}
