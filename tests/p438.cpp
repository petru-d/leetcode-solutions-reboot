#include "pch.h"

#include "../problems/p438.h"

TEST(p438, t0)
{
    p438::Solution s;
    auto res = s.findAnagrams("cbaebabacd", "abc");

    std::vector<int> expected = {0, 6};
    EXPECT_EQ(res, expected);
}

TEST(p438, t1)
{
    p438::Solution s;
    auto res = s.findAnagrams("abab", "ab");

    std::vector<int> expected = {0, 1, 2};
    EXPECT_EQ(res, expected);
}
