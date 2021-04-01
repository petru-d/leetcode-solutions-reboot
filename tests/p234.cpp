#include "pch.h"

#include "../problems/p234.h"

TEST(p234, t0)
{
    p234::Solution s;
    auto res = s.isPalindrome(make_list({1, 2}));
    EXPECT_FALSE(res);
}
