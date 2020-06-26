#include "pch.h"

#include "../problems/p287.h"

TEST(p287, t0)
{
    p287::Solution s;

    std::vector<int> nums = {1, 3, 4, 2, 2};
    auto res = s.findDuplicate(nums);

    EXPECT_EQ(res, 2);
}

TEST(p287, t1)
{
    p287::Solution s;

    std::vector<int> nums = {2, 2, 2, 2, 2};
    auto res = s.findDuplicate(nums);

    EXPECT_EQ(res, 2);
}
