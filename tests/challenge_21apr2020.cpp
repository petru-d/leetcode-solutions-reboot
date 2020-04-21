#include "pch.h"

#include "../problems/challenge_21apr2020.h"

TEST(challenge_21apr2020, t0)
{
    challenge_21apr2020::BinaryMatrix mat({{0, 0}, {1, 1}});

    challenge_21apr2020::Solution s;
    auto result = s.leftMostColumnWithOne(mat);

    EXPECT_EQ(result, 0);
}

TEST(challenge_21apr2020, t1)
{
    challenge_21apr2020::BinaryMatrix mat({{0, 0}, {0, 1}});

    challenge_21apr2020::Solution s;
    auto result = s.leftMostColumnWithOne(mat);

    EXPECT_EQ(result, 1);
}
TEST(challenge_21apr2020, t2)
{
    challenge_21apr2020::BinaryMatrix mat({{0, 0}, {0, 0}});

    challenge_21apr2020::Solution s;
    auto result = s.leftMostColumnWithOne(mat);

    EXPECT_EQ(result, -1);
}
TEST(challenge_21apr2020, t3)
{
    challenge_21apr2020::BinaryMatrix mat({{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 1, 1, 1}});

    challenge_21apr2020::Solution s;
    auto result = s.leftMostColumnWithOne(mat);

    EXPECT_EQ(result, 1);
}

TEST(challenge_21apr2020, t4)
{
    challenge_21apr2020::BinaryMatrix mat({{0, 0, 0, 1}, {0, 1, 1, 1}, {0, 0, 0, 1}});

    challenge_21apr2020::Solution s;
    auto result = s.leftMostColumnWithOne(mat);

    EXPECT_EQ(result, 1);
}