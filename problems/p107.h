#pragma once

#include "binary_tree_util.h"
#include <algorithm>
#include <vector>

namespace p107
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> levelOrderBottom(TreeNode* root)
        {
            std::vector<std::vector<int>> accumulator = {};

            top_to_bottom(root, 0, accumulator);

            std::reverse(accumulator.begin(), accumulator.end());
            return accumulator;
        }

        void top_to_bottom(TreeNode* root, int current_level, std::vector<std::vector<int>>& accumulator)
        {
            if (nullptr == root)
                return;

            if (accumulator.size() <= current_level)
            {
                accumulator.push_back({});
            }
            accumulator[current_level].push_back(root->val);

            if (nullptr != root->left)
                top_to_bottom(root->left, current_level + 1, accumulator);

            if (nullptr != root->right)
                top_to_bottom(root->right, current_level + 1, accumulator);
        }
    };
}