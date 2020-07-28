#include "pch.h"

#include "../problems/p106.h"

TEST(p106, t0)
{
    p106::Solution s;

    std::vector<int> inorder = {9, 3, 15, 20, 7};
    std::vector<int> postorder = {9, 15, 7, 20, 3};

    auto* tree = s.buildTree(inorder, postorder);

    EXPECT_EQ(serialize_tree(tree), "3(9,20(15,7))");
}

TEST(p106, t1)
{
    p106::Solution s;

    std::vector<int> inorder = {2, 1};
    std::vector<int> postorder = {2, 1};

    auto* tree = s.buildTree(inorder, postorder);

    EXPECT_EQ(serialize_tree(tree), "1(2,)");
}

TEST(p106, t2)
{
    p106::Solution s;

    std::vector<int> inorder = {2, 3, 1};
    std::vector<int> postorder = {3, 2, 1};

    auto* tree = s.buildTree(inorder, postorder);

    EXPECT_EQ(serialize_tree(tree), "1(2(,3),)");
}
