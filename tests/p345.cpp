#include "pch.h"

#include "../problems/p345.h"

TEST(p345, t0)
{
    p345::Solution s;

    auto res = s.reverseVowels("ae");

    EXPECT_EQ(res, "ea");
}
