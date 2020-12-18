#include "pch.h"

#include "../problems/p897.h"

TEST(p897, t0)
{
    p897::Solution s;

    auto res = s.increasingBST(deserialize_tree("1(0,2)"));

    EXPECT_EQ(serialize_tree(res), "0(,1(,2))");
}
