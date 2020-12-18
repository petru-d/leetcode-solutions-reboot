#include "pch.h"

#include "../problems/p312.h"

TEST(p312, t0)
{
    p312::Solution s;

    std::vector<int> nums = {3, 1, 5, 8};

    auto res = s.maxCoins(nums);

    EXPECT_EQ(res, 167);
}
