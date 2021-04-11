#pragma once
#include "util_binary_tree.h"
#include <numeric>
#include <vector>

namespace p1302
{
    class Solution2
    {
      public:
        int deepestLeavesSum(TreeNode* root)
        {
            if (!root)
                return 0;

            std::vector<TreeNode*> curr_level = {root};
            while (!curr_level.empty())
            {
                std::vector<TreeNode*> next_level;
                for (const auto* n : curr_level)
                {
                    if (n->left)
                        next_level.push_back(n->left);
                    if (n->right)
                        next_level.push_back(n->right);
                }

                if (next_level.empty())
                {
                    return std::accumulate(curr_level.begin(), curr_level.end(), 0,
                                           [](int a, TreeNode* n) { return a + n->val; });
                }
                else
                {
                    std::swap(curr_level, next_level);
                }
            }

            return -1;
        }
    };

    class Solution
    {
      public:
        int deepestLeavesSum(TreeNode* root)
        {
            go(root, 0);
            return _sum;
        }

        void go(TreeNode* curr, size_t curr_level)
        {
            if (!curr)
                return;

            if (!curr->left && !curr->right)
            {
                if (curr_level == _sum_level)
                    _sum += curr->val;
                else if (curr_level > _sum_level)
                {
                    _sum = curr->val;
                    _sum_level = curr_level;
                }
                else
                    ;

                return;
            }

            go(curr->left, curr_level + 1);
            go(curr->right, curr_level + 1);
        }

        size_t _sum_level = 0;
        int _sum = 0;
    };
}
