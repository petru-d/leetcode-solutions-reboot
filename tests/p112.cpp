#include "pch.h"

#include "../problems/p112.h"

TEST(p112, t0)
{
    p112::Solution s;
    auto res = s.hasPathSum(deserialize_tree("1(2,3)"), 5);

    EXPECT_FALSE(res);
}
