#include "pch.h"

#include "../problems/p1022.h"

TEST(p1022, t0)
{
    p1022::Solution s;

    auto sum = s.sumRootToLeaf(deserialize_tree("1(0(0,1),1(0,1))"));
    EXPECT_EQ(sum, 22);
}
