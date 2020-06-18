#include "pch.h"

#include "../problems/p130.h"

TEST(p130, t0)
{
    p130::Solution s;

    std::vector<std::vector<char>> board = {
        {'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    s.solve(board);

    std::vector<std::vector<char>> exp = {{'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'X', 'X', 'X'}, {'X', 'O', 'X', 'X'}};

    EXPECT_EQ(board, exp);
}
