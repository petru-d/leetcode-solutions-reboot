#pragma once
#include "util_binary_tree.h"

namespace p111
{
    class Solution
    {
      public:
        int minDepth(TreeNode* root)
        {
            if (root == nullptr)
                return 0;

            int lvl = 1;
            std::vector<TreeNode*> curr = {root};
            while (!curr.empty())
            {
                std::vector<TreeNode*> next;
                for (auto* c : curr)
                {
                    if (c->left == nullptr && c->right == nullptr)
                        return lvl;
                    if (c->left != nullptr)
                        next.push_back(c->left);
                    if (c->right != nullptr)
                        next.push_back(c->right);
                }
                std::swap(curr, next);
                ++lvl;
            }

            return lvl;
        }
    };
}
