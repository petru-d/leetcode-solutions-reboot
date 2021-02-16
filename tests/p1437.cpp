#include "pch.h"

#include "../problems/p1437.h"

TEST(p1437, t0)
{
    p1437::Solution s;

    std::vector<int> nums = {1, 0, 0, 0, 1, 0, 0, 1};

    auto res = s.kLengthApart(nums, 2);

    EXPECT_TRUE(res);
}
