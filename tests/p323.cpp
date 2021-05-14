#include "pch.h"

#include "../problems/p323.h"

TEST(p323, t0)
{
    p323::Solution s;
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    auto res = s.countComponents(5, edges);
    EXPECT_EQ(res, 2);
}
