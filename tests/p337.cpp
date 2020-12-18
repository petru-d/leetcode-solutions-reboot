#include "pch.h"

#include "../problems/p337.h"

TEST(p337, t0)
{
    p337::Solution s;

    auto res = s.rob(deserialize_tree("3(2(,3),3(,1))"));

    EXPECT_EQ(res, 7);
}
