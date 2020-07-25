#include "pch.h"

#include "../problems/p79.h"

TEST(p79, t0)
{
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    p79::Solution s;
    auto res = s.exist(board, "ABCCED");

    EXPECT_TRUE(res);
}

TEST(p79, t1)
{
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    p79::Solution s;
    auto res = s.exist(board, "SEE");

    EXPECT_TRUE(res);
}

TEST(p79, t2)
{
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};

    p79::Solution s;
    auto res = s.exist(board, "ABCB");

    EXPECT_FALSE(res);
}

TEST(p79, t3)
{
    std::vector<std::vector<char>> board = {{'a'}};

    p79::Solution s;
    auto res = s.exist(board, "a");

    EXPECT_TRUE(res);
}
TEST(p79, t4)
{
    std::vector<std::vector<char>> board = {{'a'}};

    p79::Solution s;
    auto res = s.exist(board, "b");

    EXPECT_FALSE(res);
}
