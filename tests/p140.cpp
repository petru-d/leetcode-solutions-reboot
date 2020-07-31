#include "pch.h"

#include "../problems/p140.h"

TEST(p140, t0)
{
    p140::Solution s;

    std::vector<std::string> dict = {"cat", "cats", "and", "sand", "dog"};

    auto res = s.wordBreak("catsanddog", dict);

    std::vector<std::string> expected = {"cat sand dog", "cats and dog"};

    EXPECT_EQ(res, expected);
}

TEST(p140, t1)
{
    p140::Solution s;

    std::vector<std::string> dict = {"apple", "pen", "applepen", "pine", "pineapple"};

    auto res = s.wordBreak("pineapplepenapple", dict);

    std::vector<std::string> expected = {"pine apple pen apple", "pine applepen apple", "pineapple pen apple"};

    EXPECT_EQ(res, expected);
}

TEST(p140, t2)
{
    p140::Solution s;

    std::vector<std::string> dict = {"cats", "dog", "sand", "and", "cat"};

    auto res = s.wordBreak("catsandog", dict);

    std::vector<std::string> expected = {};

    EXPECT_EQ(res, expected);
}

TEST(p140, t3)
{
    p140::Solution s;

    std::vector<std::string> dict = {"a",      "aa",      "aaa",      "aaaa",      "aaaaa",
                                     "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"};

    auto res = s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaa"
                           "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
                           dict);

    std::vector<std::string> expected = {};

    EXPECT_EQ(res, expected);
}