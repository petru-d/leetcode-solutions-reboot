#include "pch.h"

#include "../problems/p459.h"

TEST(p459, t0)
{
    p459::Solution s;

    auto res = s.repeatedSubstringPattern("abcabcabcabc");

    EXPECT_TRUE(res);
}
