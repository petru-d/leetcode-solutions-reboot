#include "pch.h"

#include "../problems/p63.h"

TEST(p63, t0)
{
    p63::Solution s;

    std::vector<std::vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    auto res = s.uniquePathsWithObstacles(grid);

    EXPECT_EQ(res, 2);
}
