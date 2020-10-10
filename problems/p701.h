#pragma once
#include "util_binary_tree.h"

namespace p701
{
    class Solution
    {
      public:
        TreeNode* insertIntoBST(TreeNode* root, int val)
        {
            if (root == nullptr)
                return new TreeNode(val);

            go(root, val);
            return root;
        }

        void go(TreeNode* root, int val)
        {
            if (val < root->val)
            {
                if (root->left == nullptr)
                    root->left = new TreeNode(val);
                else
                    go(root->left, val);
            }
            else
            {
                if (root->right == nullptr)
                    root->right = new TreeNode(val);
                else
                    go(root->right, val);
            }
        }
    };
}
