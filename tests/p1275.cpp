#include "pch.h"

#include "../problems/p1275.h"

TEST(p1275, t0)
{
    p1275::Solution s;

    std::vector<std::vector<int>> moves = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
    auto res = s.tictactoe(moves);
    EXPECT_EQ(res, "A");
}
