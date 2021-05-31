#include "pch.h"

#include "../problems/p709.h"

TEST(p709, t0)
{
    p709::Solution s;
    auto res = s.toLowerCase("A");
    EXPECT_EQ(res, "a");
}
