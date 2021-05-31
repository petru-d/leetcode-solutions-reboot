#include "pch.h"

#include "../problems/p52.h"

TEST(p52, t0)
{
    p52::Solution s;
    auto res = s.totalNQueens(4);
    EXPECT_EQ(res, 2);
}
