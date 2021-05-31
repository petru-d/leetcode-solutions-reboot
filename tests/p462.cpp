#include "pch.h"

#include "../problems/p462.h"

TEST(p462, t0)
{
    std::vector<int> nums = {1, 2, 3};
    p462::Solution s;
    auto res = s.minMoves2(nums);
    EXPECT_EQ(res, 2);
}
