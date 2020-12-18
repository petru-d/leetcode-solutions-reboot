#pragma once
#include "util_binary_tree.h"

namespace p104
{
    class Solution
    {
      public:
        int maxDepth(TreeNode* root)
        {
            if (!root)
                return 0;

            return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
        }
    };
}
