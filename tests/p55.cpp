#include "pch.h"

#include "../problems/p55.h"

TEST(p55, t0)
{
    p55::Solution s;

    std::vector<int> nums = {2, 3, 1, 1, 4, 5};
    auto res = s.canJump(nums);

    EXPECT_EQ(res, true);
}

TEST(p55, t1)
{
    p55::Solution s;

    std::vector<int> nums = {3, 2, 1, 0, 4};
    auto res = s.canJump(nums);

    EXPECT_EQ(res, false);
}

TEST(p55, t2)
{
    p55::Solution s;

    std::vector<int> nums = {2, 0, 0};
    auto res = s.canJump(nums);

    EXPECT_EQ(res, true);
}
