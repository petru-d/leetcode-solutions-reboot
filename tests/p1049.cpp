#include "pch.h"

#include "../problems/p1049.h"

TEST(p1049, t0)
{
    p1049::Solution s;

    std::vector<int> stones = {2, 7, 4, 1, 8, 1};

    auto res = s.lastStoneWeightII(stones);

    EXPECT_EQ(res, 1);
}
