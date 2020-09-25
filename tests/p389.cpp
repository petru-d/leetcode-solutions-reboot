#include "pch.h"

#include "../problems/p389.h"

TEST(p389, t0)
{
    p389::Solution s;

    auto res = s.findTheDifference("bubu", "bubux");

    EXPECT_EQ(res, 'x');
}
