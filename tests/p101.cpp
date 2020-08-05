#include "pch.h"

#include "../problems/p101.h"

TEST(p101, t0)
{
    p101::Solution s;

    auto* t = deserialize_tree("1(2,2)");

    auto res = s.isSymmetric(t);

    EXPECT_TRUE(res);
}
