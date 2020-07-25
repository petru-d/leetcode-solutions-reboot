#include "pch.h"

#include "../problems/p797.h"

TEST(p797, t0)
{
    p797::Solution s;

    std::vector<std::vector<int>> graph = {{1, 2}, {3}, {3}, {}};

    auto res = s.allPathsSourceTarget(graph);

    std::vector<std::vector<int>> expected = {{0, 1, 3}, {0, 2, 3}};

    EXPECT_EQ(res, expected);
}

TEST(p797, t1)
{
    p797::Solution s;

    std::vector<std::vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};

    auto res = s.allPathsSourceTarget(graph);

    std::vector<std::vector<int>> expected = {{0, 4}, {0, 3, 4}, {0, 1, 4}, {0, 1, 3, 4}, {0, 1, 2, 3, 4}};

    EXPECT_EQ(res, expected);
}
