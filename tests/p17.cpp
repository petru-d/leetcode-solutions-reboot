#include "pch.h"

#include "../problems/p17.h"

TEST(p17, t0)
{
    p17::Solution s;
    auto res = s.letterCombinations("23");

    std::vector<std::string> expected = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), expected.begin(), expected.end()));
}
