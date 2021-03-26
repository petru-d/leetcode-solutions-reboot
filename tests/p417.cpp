#include "pch.h"

#include "../problems/p417.h"

TEST(p417, t0)
{
    p417::Solution s;

    std::vector<std::vector<int>> matrix = {{0, 1}, {1, 0}};

    auto res = s.pacificAtlantic(matrix);

    std::vector<std::vector<int>> exp = {{0, 1}, {1, 0}};

    EXPECT_TRUE(std::is_permutation(res.begin(), res.end(), exp.begin()));
}
