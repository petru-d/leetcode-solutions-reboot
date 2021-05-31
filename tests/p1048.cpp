#include "pch.h"

#include "../problems/p1048.h"

TEST(p1048, t0)
{
    std::vector<std::string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    p1048::Solution s;
    auto res = s.longestStrChain(words);
    EXPECT_EQ(res, 4);
}
