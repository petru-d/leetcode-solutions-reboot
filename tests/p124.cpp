#include "pch.h"

#include "../problems/p124.h"

TEST(p124, t0)
{
    p124::Solution s;

    auto* r = make_binary_tree(2, 1, 3);

    EXPECT_EQ(6, s.maxPathSum(r));
}

TEST(p124, t1)
{
    p124::Solution s;

    auto* t20 = make_binary_tree(15, 20, 7);
    auto* t9 = make_binary_tree(9);
    auto* r = make_binary_tree(t9, -10, t20);

    EXPECT_EQ(42, s.maxPathSum(r));
}
