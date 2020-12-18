#include "pch.h"

#include "../problems/p1123.h"

TEST(p1123, t0)
{
    [[maybe_unused]] p1123::Solution s;

    auto tree = deserialize_tree("1");
    auto* res = s.lcaDeepestLeaves(tree);

    ASSERT_TRUE(res != nullptr);
    EXPECT_EQ(res->val, 1);
}
