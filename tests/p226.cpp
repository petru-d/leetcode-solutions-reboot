#include "pch.h"

#include "../problems/p226.h"

TEST(p226, t0)
{
    p226::Solution s;
    auto* res = s.invertTree(make_binary_tree(1, 2, 3));

    auto* expected = make_binary_tree(3, 2, 1);

    EXPECT_TRUE(equal_trees(res, expected));
}