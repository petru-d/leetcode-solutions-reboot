#include "pch.h"

#include "../problems/p500.h"

TEST(p500, t0)
{
    p500::Solution s;

    std::vector<std::string> words = {"Hello", "Alaska", "Dad", "Peace"};
    auto less_words = s.findWords(words);
    std::vector<std::string> expected = {"Alaska", "Dad"};
    EXPECT_EQ(less_words, expected);
}
