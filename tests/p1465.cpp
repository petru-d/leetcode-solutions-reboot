#include "pch.h"

#include "../problems/p1465.h"

TEST(p1465, t0)
{
    p1465::Solution s;

    std::vector<int> hc = {1, 2, 4};
    std::vector<int> vc = {1, 3};

    auto res = s.maxArea(5, 4, hc, vc);
    EXPECT_EQ(res, 4);
}
