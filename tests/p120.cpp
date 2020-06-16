#include "pch.h"

#include "../problems/p120.h"

TEST(p120, t0)
{
    p120::Solution s;

    std::vector<std::vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    auto res = s.minimumTotal(triangle);

    EXPECT_EQ(res, 11);
}
