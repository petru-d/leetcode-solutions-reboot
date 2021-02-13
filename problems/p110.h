#pragma once
#include "util_binary_tree.h"

namespace p110
{
    class Solution
    {
      public:
        bool isBalanced(TreeNode* root)
        {
            return is_balanced(root).first;
        }

        std::pair<bool, int> is_balanced(TreeNode* root)
        {
            if (!root)
                return {true, 0};

            auto [lb, lh] = is_balanced(root->left);
            if (!lb)
                return {false, -1};

            auto [rb, rh] = is_balanced(root->right);
            if (!rb)
                return {false, -1};

            if (std::abs(lh - rh) > 1)
                return {false, -1};

            return {true, 1 + std::max(lh, rh)};
        }
    };
}
