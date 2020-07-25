#include "pch.h"

#include "../problems/p1354.h"

TEST(p1354, t0)
{
    p1354::Solution s;
    std::vector<int> target{8, 5};

    auto p = s.isPossible(target);
    EXPECT_TRUE(p);
}

TEST(p1354, t1)
{
    p1354::Solution s;
    std::vector<int> target{9, 3, 5};

    auto p = s.isPossible(target);
    EXPECT_TRUE(p);
}

TEST(p1354, t2)
{
    p1354::Solution s;
    std::vector<int> target{1, 1, 1, 2};

    auto p = s.isPossible(target);
    EXPECT_FALSE(p);
}
