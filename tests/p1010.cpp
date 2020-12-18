#include "pch.h"

#include "../problems/p1010.h"

TEST(p1010, t0)
{
    p1010::Solution s;
    std::vector<int> time = {30, 20, 150, 100, 40};
    auto res = s.numPairsDivisibleBy60(time);
    EXPECT_EQ(res, 3);
}
