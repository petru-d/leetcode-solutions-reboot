#include "pch.h"

#include "../problems/p215.h"

TEST(p215, t0)
{
    p215::Solution s;

    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    auto res = s.findKthLargest(nums, 2);

    EXPECT_EQ(res, 5);
}

TEST(p215, t1)
{
    p215::Solution s;

    std::vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    auto res = s.findKthLargest(nums, 4);

    EXPECT_EQ(res, 4);
}