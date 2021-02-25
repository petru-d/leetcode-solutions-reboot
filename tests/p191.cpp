#include "pch.h"

#include "../problems/p191.h"

TEST(p191, t0)
{
    p191::Solution s;

    auto res = s.hammingWeight(17);

    EXPECT_EQ(res, 2);
}
