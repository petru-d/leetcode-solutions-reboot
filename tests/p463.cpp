#include "pch.h"

#include "../problems/p463.h"

TEST(p463, t0)
{
    p463::Solution s;

    std::vector<std::vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    auto res = s.islandPerimeter(grid);

    EXPECT_EQ(res, 16);
}
