#include "pch.h"

#include "../problems/p227.h"

TEST(p227, t0)
{
    p227::Solution s;

    auto res = s.calculate("3+2*2");
    EXPECT_EQ(res, 7);
}
