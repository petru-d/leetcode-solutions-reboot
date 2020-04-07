#include "pch.h"

#include "../problems/challenge_7apr2020.h"

TEST(challenge_7apr2020, T0)
{
    challenge_7apr2020::Solution s;

    std::vector<int> data = {1, 2, 3};
    auto result = s.countElements(data);

    EXPECT_EQ(result, 2);
}

TEST(challenge_7apr2020, T1)
{
    challenge_7apr2020::Solution s;

    std::vector<int> data = {1, 1, 3, 3, 5, 5, 7, 7};
    auto result = s.countElements(data);

    EXPECT_EQ(result, 0);
}
TEST(challenge_7apr2020, T2)
{
    challenge_7apr2020::Solution s;

    std::vector<int> data = {1, 3, 2, 3, 5, 0};
    auto result = s.countElements(data);

    EXPECT_EQ(result, 3);
}
TEST(challenge_7apr2020, T3)
{
    challenge_7apr2020::Solution s;

    std::vector<int> data = {1, 1, 2, 2};
    auto result = s.countElements(data);

    EXPECT_EQ(result, 2);
}
