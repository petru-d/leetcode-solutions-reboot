#include "pch.h"

#include "../problems/p54.h"

TEST(p54, t0)
{
    p54::Solution s;
    std::vector<std::vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = s.spiralOrder(mat);
    EXPECT_EQ(res, (std::vector<int>{1, 2, 3, 6, 9, 8, 7, 4, 5}));
}
