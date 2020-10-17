#include "pch.h"

#include "../problems/p378.h"

TEST(p378, t0)
{
    p378::Solution s;

    std::vector<std::vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};

    auto res = s.kthSmallest(matrix, 8);

    EXPECT_EQ(res, 13);
}

TEST(p378, t1)
{
    p378::Solution s;

    std::vector<std::vector<int>> matrix = {{-5}};

    auto res = s.kthSmallest(matrix, 1);

    EXPECT_EQ(res, -5);
}

TEST(p378, t2)
{
    p378::Solution s;

    std::vector<std::vector<int>> matrix = {{1, 3, 5}, {6, 7, 12}, {11, 14, 14}};

    auto res = s.kthSmallest(matrix, 7);

    EXPECT_EQ(res, 12);
}