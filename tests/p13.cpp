#include "pch.h"

#include "../problems/p13.h"

TEST(p13, t0)
{
    p13::Solution s;
    auto res = s.romanToInt("LVIII");
    EXPECT_EQ(res, 58);
}
