#include "pch.h"

#include "../problems/p69.h"

TEST(P69, T0)
{
    p69::Solution s;
    auto result = s.mySqrt(4);

    EXPECT_EQ(result, 2);
}

TEST(P69, T1)
{
    p69::Solution s;
    auto result = s.mySqrt(8);

    EXPECT_EQ(result, 2);
}

TEST(P69, T2)
{
    p69::Solution s;
    auto result = s.mySqrt(8);

    EXPECT_EQ(result, 2);
}

TEST(P69, T3)
{
    p69::Solution s;
    auto result = s.mySqrt(2147483647);

    EXPECT_EQ(result, 46340);
}

TEST(P69, T4)
{
    p69::Solution s;
    auto result = s.mySqrt(2);

    EXPECT_EQ(result, 1);
}

TEST(P69, T5)
{
    p69::Solution s;
    auto result = s.mySqrt(2147395600);

    EXPECT_EQ(result, 46340);
}