#include "pch.h"

#include "../problems/p701.h"

TEST(p701, t0)
{
    p701::Solution s;

    auto* tree = s.insertIntoBST(deserialize_tree("2(1,)"), 3);

    EXPECT_EQ(serialize_tree(tree), "2(1,3)");
}
