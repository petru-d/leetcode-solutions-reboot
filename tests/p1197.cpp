#include "pch.h"

#include "../problems/p1197.h"

TEST(p1197, t0)
{
    p1197::Solution s;
    auto res = s.minKnightMoves(5, 5);
    EXPECT_EQ(res, 4);

    p1197::Solution2 s2;
    auto res2 = s2.minKnightMoves(5, 5);
    EXPECT_EQ(res2, 4);
}
