#include "pch.h"

#include "../problems/p556.h"

TEST(p556, T0)
{
    p556::Solution s;
    auto result = s.nextGreaterElement(12);

    EXPECT_EQ(result, 21);
}

TEST(p556, T1)
{
    p556::Solution s;
    auto result = s.nextGreaterElement(21);

    EXPECT_EQ(result, -1);
}
TEST(p556, T2)
{
    p556::Solution s;
    auto result = s.nextGreaterElement(897541);

    EXPECT_EQ(result, 914578);
}
TEST(p556, T3)
{
    p556::Solution s;
    auto result = s.nextGreaterElement(398765430);

    EXPECT_EQ(result, 403356789);
}
TEST(p556, T4)
{
    p556::Solution s;
    auto result = s.nextGreaterElement(120);

    EXPECT_EQ(result, 201);
}
TEST(p556, T5)
{
    p556::Solution s;
    auto result = s.nextGreaterElement(1999999999);

    EXPECT_EQ(result, -1);
}
