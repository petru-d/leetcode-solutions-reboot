#include "pch.h"

#include "../problems/p1451.h"

TEST(p1451, t0)
{
    p1451::Solution s;

    std::string text = "Leetcode is cool";
    auto res = s.arrangeWords(text);

    EXPECT_EQ(res, "Is cool leetcode");
}
