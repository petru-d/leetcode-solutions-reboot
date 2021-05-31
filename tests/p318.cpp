#include "pch.h"

#include "../problems/p318.h"

TEST(p318, t0)
{
    std::vector<std::string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    p318::Solution s;
    auto res = s.maxProduct(words);
    EXPECT_EQ(res, 16);

    p318::Solution2 s2;
    auto res2 = s2.maxProduct(words);
    EXPECT_EQ(res2, 16);
}
