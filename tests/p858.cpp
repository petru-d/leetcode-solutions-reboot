#include "pch.h"

#include "../problems/p858.h"

TEST(p858, t0)
{
    p858::Solution s;

    auto res = s.mirrorReflection(5, 2);

    EXPECT_EQ(res, 0);
}

TEST(p858, t1)
{
    p858::Solution s;

    auto res = s.mirrorReflection(5, 3);

    EXPECT_EQ(res, 1);
}
