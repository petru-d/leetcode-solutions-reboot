#include "pch.h"

#include "../problems/p84.h"

TEST(p84, t0)
{
    p84::Solution s;

    std::vector<int> h = {2, 1, 5, 6, 2, 3};

    auto res = s.largestRectangleArea(h);

    EXPECT_EQ(res, 10);
}
