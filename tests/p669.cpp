#include "pch.h"

#include "../problems/p669.h"

TEST(p669, t0)
{
    p669::Solution s;

    auto* trimmed = s.trimBST(deserialize_tree("1(0,2)"), 1, 2);

    EXPECT_EQ(serialize_tree(trimmed), "1(,2)");
}
