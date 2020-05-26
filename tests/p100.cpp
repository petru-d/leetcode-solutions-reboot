#include "pch.h"

#include "../problems/p100.h"

TEST(p100, t0)
{
    p100::Solution s;

    auto res = s.isSameTree(nullptr, make_binary_tree(1));
    EXPECT_FALSE(res);
}