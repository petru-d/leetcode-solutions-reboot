#include "pch.h"

#include "../problems/p1038.h"

TEST(p1038, t0)
{
    p1038::Solution s;
    auto* t = s.bstToGst(deserialize_tree("0(,1)"));

    EXPECT_EQ(serialize_tree(t), "1(,1)");
}
