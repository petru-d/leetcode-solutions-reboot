#include "pch.h"

#include "../problems/p105.h"

TEST(p105, t0)
{
    std::vector<int> preorder = {3, 9, 20, 15, 7};
    std::vector<int> inorder = {9, 3, 15, 20, 7};
    p105::Solution s;

    auto tree = s.buildTree(preorder, inorder);

    EXPECT_EQ(serialize_tree(tree), "3(9,20(15,7))");
}
