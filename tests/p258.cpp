#include "pch.h"

#include "../problems/p258.h"

TEST(p258, t0)
{
    p258::Solution s;

    auto res = s.addDigits(38);

    EXPECT_EQ(res, 2);
}
