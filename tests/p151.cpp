#include "pch.h"

#include "../problems/p151.h"

TEST(p151, t0)
{
    p151::Solution s;
    auto res = s.reverseWords("the sky is blue");
    EXPECT_EQ(res, "blue is sky the");
}
