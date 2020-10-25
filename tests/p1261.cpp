#include "pch.h"

#include "../problems/p1261.h"

TEST(p1261, t0)
{
    auto* tree = deserialize_tree("-1(-1,-1)");

    p1261::FindElements s(tree);

    auto res = s.find(0);

    EXPECT_TRUE(res);
}
