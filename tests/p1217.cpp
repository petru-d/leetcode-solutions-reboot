#include "pch.h"

#include "../problems/p1217.h"

TEST(p1217, t0)
{
    p1217::Solution s;

    std::vector<int> position = {1, 2, 3};
    auto res = s.minCostToMoveChips(position);
    EXPECT_EQ(res, 1);
}
