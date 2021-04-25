#include "pch.h"

#include "../problems/p1192.h"

TEST(p1192, t0)
{
    std::vector<std::vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    p1192::Solution s;

    auto res = s.criticalConnections(4, connections);

    EXPECT_EQ(res, (std::vector<std::vector<int>>{{1, 3}}));
}
