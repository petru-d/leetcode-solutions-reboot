#include "pch.h"

#include "../problems/p213.h"

TEST(p213, t0)
{
    p213::Solution s;

    std::vector<int> houses{2, 3, 2};
    auto res = s.rob(houses);

    EXPECT_EQ(res, 3);
}
