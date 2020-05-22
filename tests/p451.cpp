#include "pch.h"

#include "../problems/p451.h"

TEST(p451, t0)
{
    p451::Solution s;

    auto res = s.frequencySort("tree");

    EXPECT_EQ(res, "eert");
}

TEST(p451, t1)
{
    p451::Solution s;

    auto res = s.frequencySort("cccaaa");

    EXPECT_EQ(res, "aaaccc");
}

TEST(p451, t2)
{
    p451::Solution s;

    auto res = s.frequencySort("Aabb");

    EXPECT_EQ(res, "bbAa");
}

TEST(p451, t3)
{
    p451::Solution s;

    auto res = s.frequencySort("2a554442f544asfasssffffasss");

    EXPECT_EQ(res, "sssssssffffff44444aaaa55522");
}

TEST(p451, t4)
{
    p451::Solution s;

    auto res = s.frequencySort(" his s he a ha he ha ae ");

    EXPECT_EQ(res, "         hhhhhaaaaeeessi");
}

TEST(p451, t5)
{
    p451::Solution s;

    auto res = s.frequencySort("zuzuz");

    EXPECT_EQ(res, "zzzuu");
}
