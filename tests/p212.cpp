#include "pch.h"

#include "../problems/p212.h"

TEST(p212, t0)
{
    p212::Solution s;

    std::vector<std::string> words = {"oath", "pea", "eat", "rain"};
    std::vector<std::vector<char>> board = {
        {'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};

    auto res = s.findWords(board, words);

    std::vector<std::string> expected = {"oath", "eat"};
    EXPECT_EQ(res, expected);
}

TEST(p212, t1)
{
    p212::Solution s;

    std::vector<std::string> words = {"a"};
    std::vector<std::vector<char>> board = {{'a'}};

    auto res = s.findWords(board, words);

    std::vector<std::string> expected = {"a"};
    EXPECT_EQ(res, expected);
}
