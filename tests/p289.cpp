#include "pch.h"

#include "../problems/p289.h"

TEST(p289, t0)
{
    p289::Solution s;

    std::vector<std::vector<int>> b = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    s.gameOfLife(b);

    EXPECT_EQ(b, std::vector<std::vector<int>>({ { 0, 0, 0 }, { 1, 0, 1 }, { 0, 1, 1 }, { 0, 1, 0 } }));
}
