#include "pch.h"

#include "../problems/p74.h"

TEST(p74, t0)
{
    p74::Solution s;

    std::vector<std::vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

    auto res = s.searchMatrix(mat, 3);

    EXPECT_TRUE(res);
}

TEST(p74, t1)
{
    p74::Solution s;

    std::vector<std::vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

    auto res = s.searchMatrix(mat, 13);

    EXPECT_FALSE(res);
}

TEST(p74, t2)
{
    p74::Solution s;

    std::vector<std::vector<int>> mat = {};

    auto res = s.searchMatrix(mat, 0);

    EXPECT_FALSE(res);
}
