#include "pch.h"

#include "../problems/p965.h"

TEST(p965, t0)
{
    p965::Solution s;
    auto res = s.isUnivalTree(make_binary_tree(1, 1, 1));
    EXPECT_TRUE(res);
}