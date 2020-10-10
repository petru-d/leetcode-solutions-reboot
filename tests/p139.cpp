#include "pch.h"

#include "../problems/p139.h"

TEST(p139, t0)
{
    p139::Solution s;

    std::string w = "leetcode";
    std::vector<std::string> dict = {"leet", "code"};

    auto res = s.wordBreak(w, dict);

    EXPECT_TRUE(res);
}
