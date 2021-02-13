#include "pch.h"

#include "../problems/p498.h"

TEST(p498, t0)
{
    [[maybe_unused]] p498::Solution s;

    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    auto res = s.findDiagonalOrder(mat);

    EXPECT_EQ(res, std::vector<int>({1, 2, 4, 7, 5, 3, 6, 8, 9}));
}
