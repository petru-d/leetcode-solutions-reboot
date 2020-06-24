#include "pch.h"

#include "../problems/p1486.h"

TEST(p1486, t0)
{
    p1486::Solution s;

    auto res = s.xorOperation(5, 0);

    EXPECT_EQ(res, 8);
}
