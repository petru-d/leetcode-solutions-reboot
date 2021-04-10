#include "pch.h"

#include "../problems/p285.h"

TEST(p285, t0)
{
    auto root = deserialize_tree("1(2,3)");

    p285::Solution s;
    auto res = s.inorderSuccessor(root, root);
    EXPECT_EQ(res, root->right);

    p285::Solution2 s2;
    res = s2.inorderSuccessor(root, root);
    EXPECT_EQ(res, root->right);
}
