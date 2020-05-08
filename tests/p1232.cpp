#include "pch.h"

#include "../problems/p1232.h"

TEST(p1232, t0)
{
    p1232::Solution s;

    std::vector<std::vector<int>> data = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};

    auto res = s.checkStraightLine(data);
    EXPECT_EQ(res, true);
}
