#include "pch.h"

#include "../problems/p1642.h"

TEST(p1642, t0)
{
    p1642::Solution s;

    std::vector<int> heights{4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10;
    int ladders = 2;

    auto res = s.furthestBuilding(heights, bricks, ladders);
    EXPECT_EQ(res, 7);
}
