#include "pch.h"

#include "../problems/p12.h"

TEST(p12, t0)
{
    p12::Solution s;
    auto res = s.intToRoman(3);
    EXPECT_EQ(res, "III");
}
