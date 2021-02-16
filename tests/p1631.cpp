#include "pch.h"

#include "../problems/p1631.h"

TEST(p1631, t0)
{
    p1631::Solution s;
    std::vector<std::vector<int>> h = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    auto res = s.minimumEffortPath(h);

    EXPECT_EQ(res, 2);
}
