#pragma once

#include "util_binary_tree.h"

#include <algorithm>
#include <queue>
#include <unordered_map>

namespace p662
{
    class Solution
    {
      public:
        int widthOfBinaryTree(TreeNode* root)
        {
            if (root == nullptr)
                return 0;

            std::queue<TreeNode*> curr_lvl;
            curr_lvl.push(root);
            int maxi = 1;

            root->val = 1;

            while (!curr_lvl.empty())
            {
                int offset = 1 + curr_lvl.back()->val - curr_lvl.front()->val;
                maxi = std::max(maxi, offset);

                int sz_curr_level = static_cast<int>(curr_lvl.size());

                for (int i = 0; i < sz_curr_level; ++i)
                {
                    auto* n = curr_lvl.front();
                    curr_lvl.pop();

                    if (n->left)
                    {
                        curr_lvl.push(n->left);
                        n->left->val = 2 * (n->val - offset);
                    }
                    if (n->right)
                    {
                        curr_lvl.push(n->right);
                        n->right->val = 2 * (n->val - offset) + 1;
                    }
                }
            }

            return maxi;
        }
    };
}
