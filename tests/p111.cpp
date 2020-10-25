#include "pch.h"

#include "../problems/p111.h"

TEST(p111, t0)
{
    p111::Solution s;

    auto* tree = deserialize_tree("1(2,3)");
    auto res = s.minDepth(tree);
    EXPECT_EQ(res, 2);
}
