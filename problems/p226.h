#pragma once

#include "util_binary_tree.h"

namespace p226
{
    class Solution
    {
      public:
        TreeNode* invertTree(TreeNode* root)
        {
            if (!root)
                return nullptr;

            invertTree(root->left);
            invertTree(root->right);
            std::swap(root->left, root->right);

            return root;
        }
    };
}