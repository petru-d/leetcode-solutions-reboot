#include "pch.h"

#include "../problems/p243.h"

TEST(p243, t0)
{
    p243::Solution s;
    std::vector<std::string> words = {"practice", "makes", "perfect", "coding", "makes"};
    auto res = s.shortestDistance(words, "coding", "practice");
    EXPECT_EQ(res, 3);
}
