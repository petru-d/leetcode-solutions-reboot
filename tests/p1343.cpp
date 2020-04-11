#include "pch.h"

#include "../problems/p1343.h"

TEST(P1343, T0)
{
    p1343::Solution s;

    std::vector<int> data = {2, 2, 2, 2, 5, 5, 5, 8};
    auto res = s.numOfSubarrays(data, 3, 4);

    EXPECT_EQ(res, 3);
}

TEST(P1343, T1)
{
    p1343::Solution s;

    std::vector<int> data = {1, 1, 1, 1, 1};
    auto res = s.numOfSubarrays(data, 1, 0);

    EXPECT_EQ(res, 5);
}

TEST(P1343, T2)
{
    p1343::Solution s;

    std::vector<int> data = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    auto res = s.numOfSubarrays(data, 3, 5);

    EXPECT_EQ(res, 6);
}

TEST(P1343, T3)
{
    p1343::Solution s;

    std::vector<int> data = {7, 7, 7, 7, 7, 7, 7};
    auto res = s.numOfSubarrays(data, 7, 7);

    EXPECT_EQ(res, 1);
}

TEST(P1343, T4)
{
    p1343::Solution s;

    std::vector<int> data = {4, 4, 4, 4};
    auto res = s.numOfSubarrays(data, 4, 1);

    EXPECT_EQ(res, 1);
}
