#include "pch.h"

#include "../problems/p348.h"

TEST(p348, t0)
{
    p348::TicTacToe s(3);

    auto res = s.move(0, 0, 1);
    EXPECT_EQ(res, 0);
    res = s.move(0, 2, 2);
    EXPECT_EQ(res, 0);
    res = s.move(2, 2, 1);
    EXPECT_EQ(res, 0);
    res = s.move(1, 1, 2);
    EXPECT_EQ(res, 0);
    res = s.move(2, 0, 1);
    EXPECT_EQ(res, 0);
    res = s.move(1, 0, 2);
    EXPECT_EQ(res, 0);
    res = s.move(2, 1, 1);
    EXPECT_EQ(res, 1);
}
