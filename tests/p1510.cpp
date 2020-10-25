#include "pch.h"

#include "../problems/p1510.h"

TEST(p1510, t0)
{
    p1510::Solution s;

    auto res = s.winnerSquareGame(1);
    EXPECT_TRUE(res);
}

TEST(p1510, t1)
{
    p1510::Solution s;

    auto res = s.winnerSquareGame(2);
    EXPECT_FALSE(res);
}

TEST(p1510, t2)
{
    p1510::Solution s;

    auto res = s.winnerSquareGame(4);
    EXPECT_TRUE(res);
}

TEST(p1510, t3)
{
    p1510::Solution s;

    auto res = s.winnerSquareGame(7);
    EXPECT_FALSE(res);
}

TEST(p1510, t4)
{
    p1510::Solution s;

    auto res = s.winnerSquareGame(17);
    EXPECT_FALSE(res);
}

TEST(p1510, t8)
{
    p1510::Solution s;

    auto res = s.winnerSquareGame(8);
    EXPECT_TRUE(res);
}
