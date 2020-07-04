#include "pch.h"

#include "../problems/p441.h"

TEST(p441, t0)
{
    p441::Solution s;

    auto res = s.arrangeCoins(5);

    EXPECT_EQ(res, 2);
}
