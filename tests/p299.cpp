#include "pch.h"

#include "../problems/p299.h"

TEST(p299, t0)
{
    p299::Solution s;

    auto res = s.getHint("1807", "7810");

    EXPECT_EQ(res, "1A3B");
}
