#include "pch.h"

#include "../problems/p1198.h"

TEST(p1198, t0)
{
    p1198::Solution s;

    std::vector<std::vector<int>> mat = {{1, 2, 3, 4, 5}, {5, 6, 7, 8, 9}};
    auto res = s.smallestCommonElement(mat);
    EXPECT_EQ(res, 5);
}
