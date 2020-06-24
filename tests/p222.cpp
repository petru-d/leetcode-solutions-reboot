#include "pch.h"

#include "../problems/p222.h"

TEST(p222, t0)
{
    p222::Solution s;

    auto* t2 = make_binary_tree(4, 2, 5);
    auto* t3 = make_binary_tree(make_binary_tree(6), 3);
    auto* t = make_binary_tree(t2, 1, t3);

    auto x = s.countNodes(t);

    EXPECT_EQ(x, 6);
}

TEST(p222, t1)
{
    p222::Solution s;

    auto* t2 = make_binary_tree(4, 2, 5);
    auto* t3 = make_binary_tree(3);
    auto* t = make_binary_tree(t2, 1, t3);

    auto x = s.countNodes(t);

    EXPECT_EQ(x, 5);
}

TEST(p222, t2)
{
    p222::Solution s;

    auto* t = make_binary_tree(2, 1, 3);

    auto x = s.countNodes(t);

    EXPECT_EQ(x, 3);
}
