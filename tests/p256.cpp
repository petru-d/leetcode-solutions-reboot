#include "pch.h"

#include "../problems/p256.h"

TEST(p256, t0)
{
    std::vector<std::vector<int>> costs{{17, 2, 17}, {16, 16, 5}, {14, 3, 19}};
    p256::Solution s;
    auto res = s.minCost(costs);
    EXPECT_EQ(res, 10);
}
