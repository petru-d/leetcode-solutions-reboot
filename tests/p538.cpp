#include "pch.h"

#include "../problems/p538.h"

TEST(p538, t0)
{
    p538::Solution s;
    auto* tree = deserialize_tree("2(0(-4,1),3)");

    auto* t = s.convertBST(tree);

    EXPECT_EQ(serialize_tree(t), "5(6(2,6),3)");
}

TEST(p538, t1)
{
    p538::Solution s;
    auto* tree = deserialize_tree("1(0(-2,),4(3,))");

    auto* t = s.convertBST(tree);

    EXPECT_EQ(serialize_tree(t), "8(8(6,),4(7,))");
}
