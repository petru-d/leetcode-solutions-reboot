#include "pch.h"

#include "../problems/p218.h"

TEST(p218, t0)
{
    p218::Solution s;

    std::vector<std::vector<int>> b = { { 0, 3, 3 }, { 1, 5, 3 }, { 2, 4, 3 }, { 3, 7, 3 } };

    auto res = s.getSkyline(b);
}
