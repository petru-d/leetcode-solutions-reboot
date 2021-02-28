#include "pch.h"

#include "../problems/p694.h"

TEST(p694, t0)
{
    std::vector<std::vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
    p694::Solution s;
    auto res = s.numDistinctIslands(grid);

    EXPECT_EQ(res, 1);
}
