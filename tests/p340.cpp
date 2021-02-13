#include "pch.h"

#include "../problems/p340.h"

TEST(p340, t0)
{
    p340::Solution s;

    auto res = s.lengthOfLongestSubstringKDistinct("eceba", 2);

    EXPECT_EQ(res, 3);
}
