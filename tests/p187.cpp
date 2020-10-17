#include "pch.h"

#include "../problems/p187.h"

TEST(p187, t0)
{
    [[maybe_unused]] p187::Solution s;

    auto res = s.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

    std::vector<std::string> expected = {"AAAAACCCCC", "CCCCCAAAAA"};

    EXPECT_EQ(res, expected);
}

TEST(p187, t1)
{
    [[maybe_unused]] p187::Solution s;

    auto res = s.findRepeatedDnaSequences("AAAAAAAAAAA");

    std::vector<std::string> expected = {"AAAAAAAAAA"};

    EXPECT_EQ(res, expected);
}
