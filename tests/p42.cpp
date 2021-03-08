#include "pch.h"

#include "../problems/p42.h"

TEST(p42, t0)
{
    p42::Solution s;
    std::vector<int> height = {4, 2, 0, 3, 2, 5};
    auto res = s.trap(height);
    EXPECT_EQ(res, 9);
}
