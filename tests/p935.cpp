#include "pch.h"

#include "../problems/p935.h"

TEST(p935, t0)
{
    p935::Solution s;

    auto res = s.knightDialer(2);

    EXPECT_EQ(res, 20);
}
