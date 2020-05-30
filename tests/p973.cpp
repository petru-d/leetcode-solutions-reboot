#include "pch.h"

#include "../problems/p973.h"

TEST(p973, t0)
{
    p973::Solution s;

    std::vector<std::vector<int>> points = {{1, 3}, {-2, 2}};
    auto res = s.kClosest(points, 1);
    std::vector<std::vector<int>> expected = {{-2, 2}};

    EXPECT_EQ(res, expected);
}

TEST(p973, t1)
{
    p973::Solution s;

    std::vector<std::vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    auto res = s.kClosest(points, 2);
    std::vector<std::vector<int>> expected = {{-2, 4}, {3, 3}};

    EXPECT_EQ(res, expected);
}