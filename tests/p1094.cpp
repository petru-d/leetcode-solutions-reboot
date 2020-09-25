#include "pch.h"

#include "../problems/p1094.h"

TEST(p1094, t0)
{
    p1094::Solution s;

    std::vector<std::vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};

    auto res = s.carPooling(trips, 4);

    EXPECT_FALSE(res);
}

TEST(p1094, t1)
{
    p1094::Solution s;

    std::vector<std::vector<int>> trips = {{2, 1, 5}, {3, 3, 7}};

    auto res = s.carPooling(trips, 5);

    EXPECT_TRUE(res);
}

TEST(p1094, t2)
{
    p1094::Solution s;

    std::vector<std::vector<int>> trips = {{2, 1, 5}, {3, 5, 7}};

    auto res = s.carPooling(trips, 3);

    EXPECT_TRUE(res);
}

TEST(p1094, t3)
{
    p1094::Solution s;

    std::vector<std::vector<int>> trips = {{3, 2, 7}, {3, 7, 9}, {8, 3, 9}};

    auto res = s.carPooling(trips, 11);

    EXPECT_TRUE(res);
}

TEST(p1094, t4)
{
    p1094::Solution s;

    std::vector<std::vector<int>> trips = {{8, 2, 3}, {4, 1, 3}, {1, 3, 6}, {8, 4, 6}, {4, 4, 8}};

    auto res = s.carPooling(trips, 12);

    EXPECT_FALSE(res);
}

TEST(p1094, t5)
{
    p1094::Solution s;

    std::vector<std::vector<int>> trips = {{1, 1, 4}, {9, 4, 9}, {9, 1, 9}, {2, 3, 5}, {4, 1, 5}, {10, 4, 5}};

    auto res = s.carPooling(trips, 33);

    EXPECT_FALSE(res);
}