#include "pch.h"

#include "../problems/p64.h"

TEST(p64, t0)
{
    p64::Solution s;

    std::vector<std::vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    int result = s.minPathSum(grid);

    EXPECT_EQ(result, 7);
}
