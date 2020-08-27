#include "pch.h"

#include "../problems/p404.h"

TEST(p404, t0)
{
    p404::Solution s;

    auto res = s.sumOfLeftLeaves(deserialize_tree("3(9,20(15,7))"));
    EXPECT_EQ(res, 24);
}
