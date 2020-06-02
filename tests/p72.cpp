#include "pch.h"

#include "../problems/p72.h"

TEST(p72, t0)
{
    p72::Solution s;
    auto res = s.minDistance("horse", "ros");
    EXPECT_EQ(res, 3);
}

TEST(p72, t1)
{
    p72::Solution s;
    auto res = s.minDistance("intention", "execution");
    EXPECT_EQ(res, 5);
}

TEST(p72, t2)
{
    p72::Solution s;
    auto res = s.minDistance("log", "g");
    EXPECT_EQ(res, 2);
}

TEST(p72, t3)
{
    p72::Solution s;
    auto res = s.minDistance("olog", "og");
    EXPECT_EQ(res, 2);
}

TEST(p72, t__)
{
    p72::Solution s;
    auto res = s.minDistance("zoologicoarchaeologist", "zoogeologist");
    EXPECT_EQ(res, 10);
}
