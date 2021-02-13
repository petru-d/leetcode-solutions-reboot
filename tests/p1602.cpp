#include "pch.h"

#include "../problems/p1602.h"

TEST(p1602, t0)
{
    p1602::Solution s;

    auto* t = deserialize_tree("1(2(,4),3(5,6))");
    auto* u = t->left->right;
    auto* r = s.findNearestRightNode(t, u);

    ASSERT_TRUE(r != nullptr);
    EXPECT_EQ(r->val, 5);
}
