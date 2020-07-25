#pragma once
#include "util_binary_tree.h"
#include <vector>

namespace p103
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
        {
            if (!root)
                return {};

            std::vector<TreeNode*> curr_level{root};
            std::vector<std::vector<int>> result = {{root->val}};

            bool l2r = false;
            while (!curr_level.empty())
            {
                std::vector<int> row;
                std::vector<TreeNode*> next_level;
                for (auto it = curr_level.rbegin(); it != curr_level.rend(); ++it)
                {
                    auto* node = *it;
                    auto* first = l2r ? node->left : node->right;
                    auto* second = l2r ? node->right : node->left;

                    if (first)
                    {
                        next_level.push_back(first);
                        row.push_back(first->val);
                    }
                    if (second)
                    {
                        next_level.push_back(second);
                        row.push_back(second->val);
                    }
                }
                curr_level = std::move(next_level);

                if (!row.empty())
                    result.push_back(std::move(row));
                l2r = !l2r;
            }
            return result;
        }
    };
}
