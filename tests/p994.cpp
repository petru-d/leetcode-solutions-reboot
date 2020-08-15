#include "pch.h"

#include "../problems/p994.h"

TEST(p994, t0)
{
    p994::Solution s;
    std::vector<std::vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};

    auto res = s.orangesRotting(grid);

    EXPECT_EQ(res, 4);
}

TEST(p994, t1)
{
    p994::Solution s;
    std::vector<std::vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};

    auto res = s.orangesRotting(grid);

    EXPECT_EQ(res, -1);
}

TEST(p994, t2)
{
    p994::Solution s;
    std::vector<std::vector<int>> grid = {{0, 2}};

    auto res = s.orangesRotting(grid);

    EXPECT_EQ(res, 0);
}
