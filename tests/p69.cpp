#include "pch.h"

#include "../problems/p69.h"

TEST(p69, t0)
{
    p69::Solution s;
    auto result = s.mySqrt(4);

    EXPECT_EQ(result, 2);
}

TEST(p69, t1)
{
    p69::Solution s;
    auto result = s.mySqrt(8);

    EXPECT_EQ(result, 2);
}

TEST(p69, t2)
{
    p69::Solution s;
    auto result = s.mySqrt(8);

    EXPECT_EQ(result, 2);
}

TEST(p69, t3)
{
    p69::Solution s;
    auto result = s.mySqrt(2147483647);

    EXPECT_EQ(result, 46340);
}

TEST(p69, t4)
{
    p69::Solution s;
    auto result = s.mySqrt(2);

    EXPECT_EQ(result, 1);
}

TEST(p69, t5)
{
    p69::Solution s;
    auto result = s.mySqrt(2147395600);

    EXPECT_EQ(result, 46340);
}