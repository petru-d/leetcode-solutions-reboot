#include "pch.h"

#include "../problems/p1026.h"

TEST(p1026, t0)
{
    p1026::Solution s;

    auto res = s.maxAncestorDiff(deserialize_tree("8(3(1,6(4,7)),10(,14(13,)))"));

    EXPECT_EQ(res, 7);
}
