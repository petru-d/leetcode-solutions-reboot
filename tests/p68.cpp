#include "pch.h"

#include "../problems/p68.h"

TEST(p68, t0)
{
    std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};

    p68::Solution s;
    auto result = s.fullJustify(words, 16);

    std::vector<std::string> expected = {"This    is    an", "example  of text", "justification.  "};
    EXPECT_EQ(result, expected);
}

TEST(p68, t1)
{
    std::vector<std::string> words = {"What", "must", "be", "acknowledgment", "shall", "be"};

    p68::Solution s;
    auto result = s.fullJustify(words, 16);

    std::vector<std::string> expected = {"What   must   be", "acknowledgment  ", "shall be        "};
    EXPECT_EQ(result, expected);
}

TEST(p68, t2)
{
    std::vector<std::string> words = {"Science", "is", "what",      "we",  "understand", "well",       "enough", "to", "explain",
                                      "to",      "a",  "computer.", "Art", "is",         "everything", "else",   "we", "do"};

    p68::Solution s;
    auto result = s.fullJustify(words, 20);

    std::vector<std::string> expected = {"Science  is  what we", "understand      well", "enough to explain to",
                                         "a  computer.  Art is", "everything  else  we", "do                  "};
    EXPECT_EQ(result, expected);
}

TEST(p68, t3)
{
    std::vector<std::string> words = {"Listen", "to", "many,", "speak", "to", "a", "few."};

    p68::Solution s;
    auto result = s.fullJustify(words, 6);

    std::vector<std::string> expected = {"Listen", "to    ", "many, ", "speak ", "to   a", "few.  "};
    EXPECT_EQ(result, expected);
}
