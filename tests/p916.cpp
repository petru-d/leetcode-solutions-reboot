#include "pch.h"

#include "../problems/p916.h"

TEST(p916, t0)
{
    p916::Solution s;

    std::vector<std::string> A = {"amazon", "apple", "facebook", "google", "leetcode"};
    std::vector<std::string> B = {"e", "o"};
    auto res = s.wordSubsets(A, B);

    std::vector<std::string> exp = {"facebook", "google", "leetcode"};

    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), exp.begin()));
}
