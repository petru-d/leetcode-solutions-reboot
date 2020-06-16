#include "pch.h"

#include "../problems/p1351.h"

TEST(p1351, t0)
{
    p1351::Solution s;

    std::vector<std::vector<int>> grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};

    auto res = s.countNegatives(grid);
    EXPECT_EQ(res, 8);

    res = s.countNegativesBS(grid);
    EXPECT_EQ(res, 8);
}
