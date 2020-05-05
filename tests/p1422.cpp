#include "pch.h"

#include "../problems/p1422.h"

TEST(p1422, t0)
{
    p1422::Solution s;
    auto res = s.maxScore("011101");
    EXPECT_EQ(res, 5);
}

TEST(p1422, t1)
{
    p1422::Solution s;
    auto res = s.maxScore("00111");
    EXPECT_EQ(res, 5);
}

TEST(p1422, t2)
{
    p1422::Solution s;
    auto res = s.maxScore("1111");
    EXPECT_EQ(res, 3);
}
