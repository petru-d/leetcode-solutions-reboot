#include "pch.h"

#include "../problems/p856.h"

TEST(p856, t0)
{
    p856::Solution s;
    auto res = s.scoreOfParentheses("(()(()))");
    EXPECT_EQ(res, 6);
}
