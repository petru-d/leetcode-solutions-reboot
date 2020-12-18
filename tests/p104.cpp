#include "pch.h"

#include "../problems/p104.h"

TEST(p104, t0)
{
    p104::Solution s;

    auto res = s.maxDepth(deserialize_tree("1(2,3)"));
    EXPECT_EQ(res, 2);
}
