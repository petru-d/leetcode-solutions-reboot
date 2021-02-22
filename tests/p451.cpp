#include "pch.h"

#include "../problems/p451.h"

TEST(p451, t0)
{
    p451::Solution s;

    auto res = s.frequencySort("trreee");

    EXPECT_EQ(res, "eeerrt");
}

TEST(p451, t1)
{
    p451::Solution s;

    auto res = s.frequencySort("cccaaa");

    auto v1 = (res == "aaaccc");
    auto v2 = (res == "cccaaa");

    EXPECT_TRUE(v1 || v2);
}
