#include "pch.h"

#include "../problems/p59.h"

TEST(p59, t0)
{
    p59::Solution s;
    auto res = s.generateMatrix(3);
    auto expected = std::vector<std::vector<int>>{{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
    EXPECT_EQ(res, expected);
}
