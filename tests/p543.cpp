#include "pch.h"

#include "../problems/p543.h"

TEST(p543, t0)
{
    p543::Solution s;

    auto* t4 = make_binary_tree(4);
    auto* t5 = make_binary_tree(5);
    auto* t2 = make_binary_tree(t4, 2, t5);
    auto* t3 = make_binary_tree(3);
    auto* t1 = make_binary_tree(t2, 1, t3);

    EXPECT_EQ(s.diameterOfBinaryTree(t1), 3);
}

TEST(p543, t1)
{
    p543::Solution s;

    auto* t1 = make_binary_tree(1);

    EXPECT_EQ(s.diameterOfBinaryTree(t1), 0);
}
