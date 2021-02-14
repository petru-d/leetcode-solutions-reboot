#include "pch.h"

#include "../problems/p1684.h"

TEST(p1684, t0)
{
    p1684::Solution s;

    std::vector<std::string> words = {"ad", "bd", "aaab", "baa", "badab"};

    auto res = s.countConsistentStrings("ab", words);

    EXPECT_EQ(res, 2);
}
