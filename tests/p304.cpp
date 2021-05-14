#include "pch.h"

#include "../problems/p304.h"

TEST(p304, t0)
{
    std::vector<std::vector<int>> matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    p304::NumMatrix n(matrix);

    auto res = n.sumRegion(2, 1, 4, 3);
    EXPECT_EQ(res, 8);
}
