#include "pch.h"

#include "../problems/p395.h"

TEST(p395, t0)
{
    p395::Solution s;

    auto res = s.longestSubstring("aaabb", 3);
    EXPECT_EQ(res, 3);
}
