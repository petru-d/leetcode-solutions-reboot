#include "pch.h"

#include "../problems/p392.h"

TEST(p392, t0)
{
    p392::Solution s;

    auto res = s.isSubsequence("abc", "ahbgdc");
    EXPECT_TRUE(res);
}
