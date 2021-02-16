#include "pch.h"

#include "../problems/p1329.h"

TEST(p1329, t0)
{
    p1329::Solution s;

    std::vector<std::vector<int>> mat = {{2, 1}, {1, 0}};

    mat = s.diagonalSort(mat);

    EXPECT_EQ(mat, std::vector<std::vector<int>>({{0, 1}, {1, 2}}));
}
