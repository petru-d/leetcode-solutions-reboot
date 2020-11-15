#pragma once
#include "util_binary_tree.h"

namespace p1026
{
   
    class Solution
    {
      public:
        int maxAncestorDiff(TreeNode* root)
        {
            if (root == nullptr)
                return 0;

            int gmax = 0;
            go(root, gmax);

            return gmax;
        }

        std::pair<int, int> go(TreeNode* root, int& gmax)
        {
            int min = root->val;
            int max = root->val;
            if (root->left)
            {
                auto [m, M] = go(root->left, gmax);
                min = std::min(min, m);
                max = std::max(max, M);
            }
            if (root->right)
            {
                auto [m, M] = go(root->right, gmax);
                min = std::min(min, m);
                max = std::max(max, M);
            }

            gmax = std::max({gmax, abs(root->val - min), abs(root->val - max)});

            return {std::min(min, root->val), std::max(max, root->val)};
        }
    };

}
