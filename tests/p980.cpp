#include "pch.h"

#include "../problems/p980.h"

TEST(p980, t0)
{
    p980::Solution s;

    std::vector<std::vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}};

    auto res = s.uniquePathsIII(grid);

    EXPECT_EQ(res, 2);
}

TEST(p980, t1)
{
    p980::Solution s;

    std::vector<std::vector<int>> grid = {{1, 2}};

    auto res = s.uniquePathsIII(grid);

    EXPECT_EQ(res, 1);
}
