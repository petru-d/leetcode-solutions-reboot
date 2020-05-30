#include "pch.h"

#include "../problems/p207.h"

TEST(p207, t0)
{
    p207::Solution s;

    std::vector<std::vector<int>> prereqs = {{1, 0}};

    auto res = s.canFinish(2, prereqs);
    EXPECT_TRUE(res);
}

TEST(p207, t1)
{
    p207::Solution s;

    std::vector<std::vector<int>> prereqs = {{1, 0}, {0, 1}};

    auto res = s.canFinish(2, prereqs);
    EXPECT_FALSE(res);
}

TEST(p207, t2)
{
    p207::Solution s;

    std::vector<std::vector<int>> prereqs = {{0, 1}, {0, 2}, {1, 2}};

    auto res = s.canFinish(3, prereqs);
    EXPECT_TRUE(res);
}

TEST(p207, t3)
{
    p207::Solution s;

    std::vector<std::vector<int>> prereqs = {{0, 1}, {3, 1}, {1, 3}, {3, 2}};

    auto res = s.canFinish(4, prereqs);
    EXPECT_FALSE(res);
}
