#include "pch.h"

#include "../problems/p1559.h"

TEST(p1559, t0)
{
    p1559::Solution s;
    std::vector<std::vector<char>> grid = {
        {'a', 'a', 'a', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'b', 'b', 'a'}, {'a', 'a', 'a', 'a'}};

    auto res = s.containsCycle(grid);
    EXPECT_TRUE(res);
}
