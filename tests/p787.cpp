#include "pch.h"

#include "../problems/p787.h"

TEST(p787, t0)
{
    p787::Solution s;

    std::vector<std::vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};

    auto res = s.findCheapestPrice(3, edges, 0, 2, 1);

    EXPECT_EQ(res, 200);
}

TEST(p787, t1)
{
    p787::Solution s;

    std::vector<std::vector<int>> edges = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};

    auto res = s.findCheapestPrice(3, edges, 0, 2, 0);

    EXPECT_EQ(res, 500);
}

TEST(p787, t2)
{
    p787::Solution s;

    std::vector<std::vector<int>> edges = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};

    auto res = s.findCheapestPrice(4, edges, 0, 3, 1);

    EXPECT_EQ(res, 6);
}
