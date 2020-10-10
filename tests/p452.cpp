#include "pch.h"

#include "../problems/p452.h"

TEST(p452, t0)
{
    p452::Solution s;

    std::vector<std::vector<int>> baloons = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    auto res = s.findMinArrowShots(baloons);

    EXPECT_EQ(res, 2);
}

TEST(p452, t1)
{
    p452::Solution s;

    std::vector<std::vector<int>> baloons = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};

    auto res = s.findMinArrowShots(baloons);

    EXPECT_EQ(res, 4);
}

TEST(p452, t2)
{
    p452::Solution s;

    std::vector<std::vector<int>> baloons = {{1, 2}};

    auto res = s.findMinArrowShots(baloons);

    EXPECT_EQ(res, 1);
}

TEST(p452, t3)
{
    p452::Solution s;

    std::vector<std::vector<int>> baloons = {{2, 3}, {2, 3}};

    auto res = s.findMinArrowShots(baloons);

    EXPECT_EQ(res, 1);
}
