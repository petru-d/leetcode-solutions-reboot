#include "pch.h"

#include "../problems/p88.h"

TEST(P88, T0)
{
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};

    p88::Solution s;
    s.merge(nums1, 3, nums2, 3);

    std::vector<int> expected = {1, 2, 2, 3, 5, 6};
    EXPECT_EQ(nums1, expected);
}

TEST(P88, T1)
{
    std::vector<int> nums1 = {0};
    std::vector<int> nums2 = {1};

    p88::Solution s;
    s.merge(nums1, 0, nums2, 1);

    std::vector<int> expected = {1};
    EXPECT_EQ(nums1, expected);
}