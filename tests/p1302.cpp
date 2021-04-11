#include "pch.h"

#include "../problems/p1302.h"

TEST(p1302, t0)
{
    auto* tree = deserialize_tree("1(2,3)");

    p1302::Solution s;
    auto res = s.deepestLeavesSum(tree);
    EXPECT_EQ(res, 5);

    p1302::Solution2 s2;
    res = s2.deepestLeavesSum(tree);
    EXPECT_EQ(res, 5);
}
