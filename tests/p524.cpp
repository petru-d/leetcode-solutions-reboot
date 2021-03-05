#include "pch.h"

#include "../problems/p524.h"

TEST(p524, t0)
{
    p524::Solution s;

    std::vector<std::string> dictionary{"ale", "apple", "monkey", "plea"};
    auto res = s.findLongestWord("abpcplea", dictionary);
    EXPECT_EQ(res, "apple");
}
