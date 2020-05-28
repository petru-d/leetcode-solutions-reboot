#include "pch.h"

#include "../problems/p886.h"

TEST(p886, t0)
{
    p886::Solution s;

    std::vector<std::vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 4}};

    auto res = s.possibleBipartition(4, dislikes);

    EXPECT_TRUE(res);
}

TEST(p886, t1)
{
    p886::Solution s;

    std::vector<std::vector<int>> dislikes = {{1, 2}, {1, 3}, {2, 3}};

    auto res = s.possibleBipartition(3, dislikes);

    EXPECT_FALSE(res);
}

TEST(p886, t2)
{
    p886::Solution s;

    std::vector<std::vector<int>> dislikes = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {1, 5}};

    auto res = s.possibleBipartition(5, dislikes);

    EXPECT_FALSE(res);
}