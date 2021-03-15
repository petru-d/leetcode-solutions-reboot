#include "pch.h"

#include "../problems/p536.h"

TEST(p536, t0)
{
    p536::Solution s;

    auto* tree = s.str2tree("1(2)(3)");
    EXPECT_EQ(serialize_tree(tree), "1(2,3)");
}
