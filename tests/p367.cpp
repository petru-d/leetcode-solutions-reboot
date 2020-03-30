#include "pch.h"

#include "../problems/p367.h"

TEST(P367, T0)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(4);

    EXPECT_EQ(result, true);
}

TEST(P367, T1)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(16);

    EXPECT_EQ(result, true);
}

TEST(P367, T2)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(14);

    EXPECT_EQ(result, false);
}

TEST(P367, T3)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(2147483647);

    EXPECT_EQ(result, false);
}

TEST(P367, T4)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(2);

    EXPECT_EQ(result, false);
}

TEST(P367, T5)
{
    p367::Solution s;
    auto result = s.isPerfectSquare(2147395600);

    EXPECT_EQ(result, true);
}