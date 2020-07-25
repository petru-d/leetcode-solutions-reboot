#include "pch.h"

#include "../problems/p154.h"

TEST(p154, t0)
{
    p154::Solution s;

    std::vector<int> nums = {1, 3, 5};

    auto res = s.findMin(nums);

    EXPECT_EQ(res, 1);
}

TEST(p154, t1)
{
    p154::Solution s;

    std::vector<int> nums = {2, 2, 2, 0, 1};

    auto res = s.findMin(nums);

    EXPECT_EQ(res, 0);
}
