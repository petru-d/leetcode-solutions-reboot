#include "pch.h"

#include "../problems/p202.h"

TEST(p202, t0)
{
    p202::Solution s;

    auto happy = s.isHappy(19);

    EXPECT_EQ(happy, true);
}

TEST(p202, t1)
{
    p202::Solution s;

    auto happy = s.isHappy(19);

    EXPECT_EQ(happy, true);
}

TEST(p202, t2)
{
    p202::Solution s;

    auto happy = s.isHappy(1114);

    EXPECT_EQ(happy, true);
}

TEST(p202, t3)
{
    p202::Solution s;

    auto happy = s.isHappy(2);

    EXPECT_EQ(happy, false);
}