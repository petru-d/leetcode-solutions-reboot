#include "pch.h"

#include "../problems/p200.h"

TEST(p200, t0)
{
    p200::Solution s;

    std::vector<std::vector<char>> grid = {{'1', '1', '1', '1'}, //
                                           {'1', '1', '1', '1'}, //
                                           {'1', '1', '1', '1'}, //
                                           {'1', '1', '1', '1'}};

    auto result = s.numIslands(grid);
    EXPECT_EQ(result, 1);
}

TEST(p200, t1)
{
    p200::Solution s;

    std::vector<std::vector<char>> grid = {{'1', '1', '1', '1', '0'}, //
                                           {'1', '1', '0', '1', '0'}, //
                                           {'1', '1', '0', '0', '0'}, //
                                           {'0', '0', '0', '0', '0'}};

    auto result = s.numIslands(grid);
    EXPECT_EQ(result, 1);
}

TEST(p200, t2)
{
    p200::Solution s;

    std::vector<std::vector<char>> grid = {{'1', '1', '0', '0', '0'}, //
                                           {'1', '1', '0', '0', '0'}, //
                                           {'0', '0', '1', '0', '0'}, //
                                           {'0', '0', '0', '1', '1'}};

    auto result = s.numIslands(grid);
    EXPECT_EQ(result, 3);
}