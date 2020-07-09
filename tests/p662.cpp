#include "pch.h"

#include "../problems/p662.h"

TEST(p662, t0)
{
    p662::Solution s;

    auto* tree = deserialize_tree("1(3(5,3),2(,9))");

    auto res = s.widthOfBinaryTree(tree);

    EXPECT_EQ(res, 4);
}
