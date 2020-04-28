#include "pch.h"

#include "../problems/p221.h"

TEST(p221, t0)
{
    std::vector<std::vector<char>> data = {//
                                           {'1', '0', '1', '0', '0'},
                                           {'1', '0', '1', '1', '1'},
                                           {'1', '1', '1', '1', '1'},
                                           {'1', '0', '0', '1', '0'}};

    p221::Solution s;

    auto res = s.maximalSquare(data);

    EXPECT_EQ(res, 4);
}

TEST(p221, t1)
{
    std::vector<std::vector<char>> data = {{'1'}};

    p221::Solution s;

    auto res = s.maximalSquare(data);

    EXPECT_EQ(res, 1);
}
