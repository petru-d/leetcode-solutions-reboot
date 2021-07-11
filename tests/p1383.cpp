#include "pch.h"

#include "../problems/p1383.h"

TEST(p1383, t0)
{
    int n = 6;
    std::vector<int> speed = {2, 10, 3, 1, 5, 8};
    std::vector<int> efficiency = {5, 4, 3, 9, 7, 2};
    int k = 2;

    p1383::Solution s;
    auto res = s.maxPerformance(n, speed, efficiency, k);
    EXPECT_EQ(res, 60);
}
