#include "pch.h"

#include "../problems/p931.h"

TEST(p931, t0)
{
    p931::Solution s;

    std::vector<std::vector<int>> A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = s.minFallingPathSum(A);
    EXPECT_EQ(res, 12);
}