#pragma once
#include "util_binary_tree.h"

namespace p1038
{
    class Solution
    {
      public:
        TreeNode* bstToGst(TreeNode* root)
        {
            if (root == nullptr)
                return root;

            go(root, 0);
            return root;
        }

        // return sum of left subtree, add to root sum of right subtree
        int go(TreeNode* root, int v)
        {
            if (nullptr == root)
                return v;

            root->val += go(root->right, v);

            return go(root->left, root->val);
        }
    };
}
