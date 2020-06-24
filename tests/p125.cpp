#include "pch.h"

#include "../problems/p125.h"

TEST(p125, t0)
{
    p125::Solution s;
    auto res = s.isPalindrome("A man, a plan, a canal: Panama");

    EXPECT_TRUE(res);
}
