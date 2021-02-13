#include "pch.h"

#include "../problems/p110.h"

TEST(p110, t0)
{
    p110::Solution s;

    auto* t = deserialize_tree("3(1,2)");

    auto res = s.isBalanced(t);

    EXPECT_TRUE(res);
}
