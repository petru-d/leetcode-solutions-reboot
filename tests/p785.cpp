#include "pch.h"

#include "../problems/p785.h"

TEST(p785, t0)
{
    p785::Solution s;
    std::vector<std::vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    auto res = s.isBipartite(graph);
    EXPECT_FALSE(res);
}
