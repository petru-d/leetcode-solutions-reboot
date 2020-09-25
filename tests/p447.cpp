#include "pch.h"

#include "../problems/p447.h"

TEST(p447, t0)
{
    p447::Solution s;

    std::vector<std::vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};

    auto booms = s.numberOfBoomerangs(points);

    EXPECT_EQ(booms, 2);
}

TEST(p447, t1)
{
    p447::Solution s;

    std::vector<std::vector<int>> points = {{1, 8}, {7, 9}, {2, 0}, {2, 3}, {7, 5}, {9, 2}, {2, 8}, {9, 7}, {3, 6}, {1, 2}};

    auto booms = s.numberOfBoomerangs(points);

    EXPECT_EQ(booms, 12);
}
