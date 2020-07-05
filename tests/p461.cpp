#include "pch.h"

#include "../problems/p461.h"

TEST(p461, t0)
{
    p461::Solution s;
    auto res = s.hammingDistance(1, 4);

    EXPECT_EQ(res, 2);
}
