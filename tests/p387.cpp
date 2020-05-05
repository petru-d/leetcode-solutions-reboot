#include "pch.h"

#include "../problems/p387.h"

TEST(p387, t0)
{
    p387::Solution s;

    auto result = s.firstUniqChar("leetcode");

    EXPECT_EQ(result, 0);
}

TEST(p387, t1)
{
    p387::Solution s;

    auto result = s.firstUniqChar("loveleetcode");

    EXPECT_EQ(result, 2);
}
