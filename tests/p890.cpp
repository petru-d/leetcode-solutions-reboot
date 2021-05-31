#include "pch.h"

#include "../problems/p890.h"

TEST(p890, t0)
{
    std::vector<std::string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};

    p890::Solution s;
    auto res = s.findAndReplacePattern(words, "abb");
    std::vector<std::string> exp = {"mee", "aqq"};

    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), exp.begin(), exp.end()));
}
