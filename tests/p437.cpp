#include "pch.h"

#include "../problems/p437.h"

TEST(p437, t0)
{
    p437::Solution s;

    auto* tree = deserialize_tree("10(5(3(3,-2),2(,1)),-3(,11))");

    auto result = s.pathSum(tree, 8);

    EXPECT_EQ(result, 3);
}
