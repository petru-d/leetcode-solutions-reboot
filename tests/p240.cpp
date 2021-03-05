#include "pch.h"

#include "../problems/p240.h"

TEST(p240, t0)
{
    p240::Solution s;

    std::vector<std::vector<int>> mat = {
        {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};

    auto lcres = s.searchMatrix(mat, 5);
    auto myres = s.searchMatrix_mine(mat, 5);
    auto prres = s.searchMatrix_per_row(mat, 5);

    EXPECT_TRUE(lcres && myres && prres);
}
