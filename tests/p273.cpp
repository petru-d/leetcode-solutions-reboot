#include "pch.h"

#include "../problems/p273.h"

TEST(p273, t0)
{
    p273::Solution s;

    auto res = s.numberToWords(123);

    EXPECT_EQ(res, "One Hundred Twenty Three");
}
