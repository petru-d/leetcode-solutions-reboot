#include "pch.h"

#include "../problems/p98.h"

TEST(p98, t0)
{
    p98::Solution s;
    auto res = s.isValidBST(deserialize_tree("2(1,3)"));
    EXPECT_TRUE(res);
}
