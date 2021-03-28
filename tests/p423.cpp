#include "pch.h"

#include "../problems/p423.h"

TEST(p423, t0)
{
    p423::Solution s;
    auto res = s.originalDigits("nnie");
    EXPECT_EQ(res, "9");
}
