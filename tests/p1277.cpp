#include "pch.h"

#include "../problems/p1277.h"

TEST(p1277, t0)
{
    p1277::Solution s;
    std::vector<std::vector<int>> mat = {{0, 1, 1, 1}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    auto res = s.countSquares(mat);
    EXPECT_EQ(res, 15);
}

TEST(p1277, t1)
{
    p1277::Solution s;
    std::vector<std::vector<int>> mat = {{1, 0, 1}, {1, 1, 0}, {1, 1, 0}};
    auto res = s.countSquares(mat);
    EXPECT_EQ(res, 7);
}