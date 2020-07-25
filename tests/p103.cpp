#include "pch.h"

#include "../problems/p103.h"

TEST(p103, t0)
{
    p103::Solution s;

    auto tree = deserialize_tree("1(2,3)");

    auto res = s.zigzagLevelOrder(tree);

    std::vector<std::vector<int>> expected = {{1}, {3, 2}};
    EXPECT_EQ(res, expected);
}
