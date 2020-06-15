#pragma once
#include "util_binary_tree.h"

namespace p700
{
    class Solution
    {
      public:
        TreeNode* searchBST(TreeNode* root, int val)
        {
            if (root == nullptr)
                return nullptr;

            if (root->val == val)
                return root;

            if (root->val < val)
                return searchBST(root->right, val);

            return searchBST(root->left, val);
        }
    };
}
