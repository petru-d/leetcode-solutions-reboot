#include "pch.h"

#include "../problems/p220.h"

TEST(p220, t0)
{
    p220::Solution s;

    std::vector<int> nums = {1, 2, 3, 1};
    auto res = s.containsNearbyAlmostDuplicate(nums, 3, 0);

    EXPECT_TRUE(res);
}

TEST(p220, t1)
{
    p220::Solution s;

    std::vector<int> nums = {1, 0, 1, 1};
    auto res = s.containsNearbyAlmostDuplicate(nums, 1, 2);

    EXPECT_TRUE(res);
}

TEST(p220, t2)
{
    p220::Solution s;

    std::vector<int> nums = {1, 2, 1};
    auto res = s.containsNearbyAlmostDuplicate(nums, 1, 1);

    EXPECT_TRUE(res);
}

TEST(p220, t3)
{
    p220::Solution s;

    std::vector<int> nums = {1, 3, 6, 2};
    auto res = s.containsNearbyAlmostDuplicate(nums, 1, 2);

    EXPECT_TRUE(res);
}

TEST(p220, t4)
{
    p220::Solution s;

    std::vector<int> nums = {1, 5, 9, 1, 5, 9};
    auto res = s.containsNearbyAlmostDuplicate(nums, 2, 3);

    EXPECT_FALSE(res);
}

TEST(p220, t5)
{
    p220::Solution s;

    std::vector<int> nums = {1};
    auto res = s.containsNearbyAlmostDuplicate(nums, 1, 1);

    EXPECT_FALSE(res);
}

TEST(p220, t6)
{
    p220::Solution s;

    std::vector<int> nums = {-3, 3};
    auto res = s.containsNearbyAlmostDuplicate(nums, 2, 4);

    EXPECT_FALSE(res);
}

TEST(p220, t7)
{
    p220::Solution s;

    std::vector<int> nums = {7, 1, 3};
    auto res = s.containsNearbyAlmostDuplicate(nums, 2, 3);

    EXPECT_TRUE(res);
}

TEST(p220, t8)
{
    p220::Solution s;

    std::vector<int> nums = {10, 15, 18, 24};
    auto res = s.containsNearbyAlmostDuplicate(nums, 3, 3);

    EXPECT_TRUE(res);
}