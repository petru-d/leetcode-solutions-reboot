#include "pch.h"

#include "../problems/p33.h"

TEST(p33, t0)
{
    p33::Solution s;

    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    auto result = s.search(nums, 0);

    EXPECT_EQ(result, 4);
}

TEST(p33, t1)
{
    p33::Solution s;

    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    auto result = s.search(nums, 3);

    EXPECT_EQ(result, -1);
}
