#include "pch.h"

#include "../problems/p953.h"

TEST(p953, t0)
{
    [[maybe_unused]] p953::Solution s;

    std::vector<std::string> words = {"hello", "leetcode"};
    auto res = s.isAlienSorted(words, "hlabcdefgijkmnopqrstuvwxyz");

    EXPECT_TRUE(res);
}
