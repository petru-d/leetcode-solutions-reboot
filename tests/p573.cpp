#include "pch.h"

#include "../problems/p573.h"

TEST(p573, t0)
{
    p573::Solution s;

    std::vector<int> tree = {2, 2};
    std::vector<int> squirrel = {4, 4};
    std::vector<std::vector<int>> nuts = {{3, 0}, {2, 5}};

    auto res = s.minDistance(5, 7, tree, squirrel, nuts);

    EXPECT_EQ(res, 12);
}
