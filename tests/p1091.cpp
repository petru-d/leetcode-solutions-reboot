#include "pch.h"

#include "../problems/p1091.h"

TEST(p1091, t0)
{
    p1091::Solution s;

    std::vector<std::vector<int>> grid = {{0, 1}, {1, 0}};
    auto res = s.shortestPathBinaryMatrix(grid);
    EXPECT_EQ(res, 2);
}
