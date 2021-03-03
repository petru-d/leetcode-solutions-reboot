#include "pch.h"

#include "../problems/p784.h"

TEST(p784, t0)
{
    p784::Solution s;

    auto res = s.letterCasePermutation("3z4");

    std::vector<std::string> exp = {"3z4", "3Z4"};

    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), exp.begin(), exp.end()));
}
