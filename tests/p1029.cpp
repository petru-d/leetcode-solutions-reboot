#include "pch.h"

#include "../problems/p1029.h"

TEST(p1029, t0)
{
    std::vector<std::vector<int>> costs = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};

    p1029::Solution s;
    auto res = s.twoCitySchedCost(costs);
    EXPECT_EQ(res, 110);
}
