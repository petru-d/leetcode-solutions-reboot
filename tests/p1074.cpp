#include "pch.h"

#include "../problems/p1074.h"

TEST(p1074, t0)
{
    std::vector<std::vector<int>> mat = {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};

    p1074::Solution s;
    auto res = s.numSubmatrixSumTarget(mat, 0);
    EXPECT_EQ(res, 4);

    p1074::Solution2 s2;
    res = s2.numSubmatrixSumTarget(mat, 0);
    EXPECT_EQ(res, 4);
}
