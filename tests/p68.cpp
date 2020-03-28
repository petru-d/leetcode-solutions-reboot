#include "pch.h"

#include "../problems/p68.h"

TEST(P68, T0)
{
    std::vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};

    p68::Solution s;
    auto result = s.fullJustify(words, 16);

    std::vector<string> expected = {"This    is    an", "example  of text", "justification.  "};
    EXPECT_EQ(result, expected);
}

TEST(P68, T1)
{
    std::vector<string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};

    p68::Solution s;
    auto result = s.fullJustify(words, 16);

    std::vector<string> expected = {"What   must   be", "acknowledgment  ", "shall be        "};
    EXPECT_EQ(result, expected);
}

TEST(P68, T2)
{
    std::vector<string> words = {"Science", "is", "what",      "we",  "understand", "well",       "enough", "to", "explain",
                                 "to",      "a",  "computer.", "Art", "is",         "everything", "else",   "we", "do"};

    p68::Solution s;
    auto result = s.fullJustify(words, 20);

    std::vector<string> expected = {"Science  is  what we", "understand      well", "enough to explain to",
                                    "a  computer.  Art is", "everything  else  we", "do                  "};
    EXPECT_EQ(result, expected);
}

TEST(P68, T3)
{
    std::vector<string> words = {"Listen", "to", "many,", "speak", "to", "a", "few."};

    p68::Solution s;
    auto result = s.fullJustify(words, 6);

    std::vector<string> expected = {"Listen", "to    ", "many, ", "speak ", "to   a", "few.  "};
    EXPECT_EQ(result, expected);
}
