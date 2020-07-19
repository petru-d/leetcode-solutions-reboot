#include "pch.h"

#include "../problems/p210.h"

TEST(p210, t0)
{
    p210::Solution s;

    std::vector<std::vector<int>> edges = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    auto res = s.findOrder(4, edges);

    std::vector<int> expected = {0, 2, 1, 3};
    EXPECT_EQ(res, expected);
}

TEST(p210, t1)
{
    p210::Solution s;

    std::vector<std::vector<int>> edges = {};
    auto res = s.findOrder(1, edges);

    std::vector<int> expected = {0};
    EXPECT_EQ(res, expected);
}

TEST(p210, t2)
{
    p210::Solution s;

    std::vector<std::vector<int>> edges = {{1, 0}, {0, 1}};
    auto res = s.findOrder(2, edges);

    std::vector<int> expected = {};
    EXPECT_EQ(res, expected);
}
