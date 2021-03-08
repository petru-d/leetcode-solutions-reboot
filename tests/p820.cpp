#include "pch.h"

#include "../problems/p820.h"

TEST(p820, t0)
{
    p820::Solution s;
    std::vector<std::string> words = {"time", "me", "bell"};
    auto res = s.minimumLengthEncoding(words);
    EXPECT_EQ(res, 10);
}
