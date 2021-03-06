#include "pch.h"

#include "../problems/p29.h"

TEST(p29, t0)
{
    p29::Solution s;

    auto res = s.divide(10, 3);
    EXPECT_EQ(res, 3);
}
