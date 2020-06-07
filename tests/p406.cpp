#include "pch.h"

#include "../problems/p406.h"

TEST(p406, t0)
{
    p406::Solution s;

    std::vector<std::vector<int>> q = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

    auto res = s.reconstructQueue(q);

    std::vector<std::vector<int>> expected = {{5, 0}, {7, 0}, {5, 2}, {6, 1}, {4, 4}, {7, 1}};

    EXPECT_EQ(res, expected);
}