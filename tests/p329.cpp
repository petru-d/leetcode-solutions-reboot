#include "pch.h"

#include "../problems/p329.h"

TEST(p329, t0)
{
    p329::Solution s;
    std::vector<std::vector<int>> mat = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    auto res = s.longestIncreasingPath(mat);
    EXPECT_EQ(res, 4);
}
