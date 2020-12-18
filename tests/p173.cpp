#include "pch.h"

#include "../problems/p173.h"

TEST(p173, t0)
{
    auto root = deserialize_tree("7(3,15(9,20))");
    p173::BSTIterator iter(root);

    auto res = iter.next();
    EXPECT_EQ(res, 3);
}
