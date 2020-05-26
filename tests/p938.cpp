#include "pch.h"

#include "../problems/p938.h"

TEST(p938, t0)
{
    auto* t5 = make_binary_tree(3, 5, 7);
    auto* t15 = make_binary_tree(nullptr, 15, make_binary_tree(18));
    auto* t = make_binary_tree(t5, 10, t15);

    p938::Solution s;
    auto sum = s.rangeSumBST(t, 7, 15);

    EXPECT_EQ(sum, 32);
}