#pragma once
#include "util_binary_tree.h"
#include <queue>

namespace p623
{
    class Solution
    {
      public:
        TreeNode* addOneRow(TreeNode* root, int v, int d)
        {
            if (d == 1)
            {
                return new TreeNode(v, root, nullptr);
            }

            std::queue<TreeNode*> curr_row;
            curr_row.push(root);
            while (!curr_row.empty())
            {
                // reached desired depth - inject row, return
                if (d == 2)
                {
                    auto sz_row = curr_row.size();
                    for (size_t i = 0; i < sz_row; ++i)
                    {
                        auto* front = curr_row.front();
                        curr_row.pop();
                        auto* n_left = new TreeNode(v, front->left, nullptr);
                        front->left = n_left;
                        auto* n_right = new TreeNode(v, nullptr, front->right);
                        front->right = n_right;
                    }
                    return root;
                }

                --d;
                auto sz_row = curr_row.size();
                for (size_t i = 0; i < sz_row; ++i)
                {
                    auto* front = curr_row.front();
                    curr_row.pop();
                    if (nullptr != front->left)
                        curr_row.push(front->left);
                    if (nullptr != front->right)
                        curr_row.push(front->right);
                }
            }

            return nullptr;
        }
    };
}
