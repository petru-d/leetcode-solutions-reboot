#include "pch.h"

#include "../problems/p58.h"

TEST(p58, t0)
{
    p58::Solution s;

    auto res = s.lengthOfLastWord("Hello World");

    EXPECT_EQ(res, 5);
}
