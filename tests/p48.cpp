#include "pch.h"

#include "../problems/p48.h"

TEST(p48, t0)
{
    std::vector<std::vector<int>> matrix = {{1, 2}, {4, 3}};
    p48::Solution s;
    s.rotate(matrix);

    EXPECT_EQ(matrix, (std::vector<std::vector<int>>{{4, 1}, {3, 2}}));
}
