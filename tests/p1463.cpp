#include "pch.h"

#include "../problems/p1463.h"

TEST(p1463, t0)
{
    p1463::Solution s;

    std::vector<std::vector<int>> grid = { { 3, 1, 1 }, { 2, 5, 1 }, { 1, 5, 5 }, { 2, 1, 1 } };

    auto res = s.cherryPickup(grid);

    EXPECT_EQ(res, 24);
}
