#include "pch.h"

#include "../problems/p1108.h"

TEST(p1108, t0)
{
    p1108::Solution s;

    auto res = s.defangIPaddr("1.1.1.1");
    EXPECT_EQ(res, "1[.]1[.]1[.]1");
}

TEST(p1108, t1)
{
    p1108::Solution s;

    auto res = s.defangIPaddr("255.100.50.0");
    EXPECT_EQ(res, "255[.]100[.]50[.]0");
}
