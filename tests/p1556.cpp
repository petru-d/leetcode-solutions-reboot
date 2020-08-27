#include "pch.h"

#include "../problems/p1556.h"

TEST(p1556, t0)
{
    p1556::Solution s;

    auto res = s.thousandSeparator(123456789);

    EXPECT_EQ(res, "123.456.789");
}
