#include "pch.h"

#include "../problems/p1155.h"

TEST(p1155, t0)
{
    p1155::Solution s;

    auto res = s.numRollsToTarget(2, 6, 7);

    EXPECT_EQ(res, 6);
}

TEST(p1155, t1)
{
    p1155::Solution s;

    auto res = s.numRollsToTarget(2, 5, 10);

    EXPECT_EQ(res, 1);
}
