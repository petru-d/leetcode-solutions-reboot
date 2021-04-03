#include "pch.h"

#include "../problems/p32.h"

TEST(p32, t0)
{
    p32::Solution s;
    auto res = s.longestValidParentheses("()");
    EXPECT_EQ(res, 2);

    p32::Solution2 s2;
    res = s2.longestValidParentheses("()");
    EXPECT_EQ(res, 2);

    p32::Solution3 s3;
    res = s3.longestValidParentheses("()");
    EXPECT_EQ(res, 2);
}
