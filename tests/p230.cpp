#include "pch.h"

#include "../problems/p230.h"

TEST(p230, t1)
{
    TreeNode* t2 = make_binary_tree(2);
    TreeNode* t1 = make_binary_tree(nullptr, 1, t2);
    TreeNode* t4 = make_binary_tree(4);
    TreeNode* t3 = make_binary_tree(t1, 3, t4);
    p230::Solution s;

    auto res = s.kthSmallest(t3, 1);

    EXPECT_EQ(res, 1);
}
