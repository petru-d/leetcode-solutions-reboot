#pragma once

#include "util_binary_tree.h"
#include <stack>

namespace p897
{
    class Solution
    {
      public:
        TreeNode* increasingBST(TreeNode* root)
        {
            std::stack<TreeNode*> nodes;

            auto go_left = [&nodes](TreeNode* root) {
                while (root)
                {
                    nodes.push(root);
                    root = root->left;
                }
            };

            TreeNode* new_root = nullptr;
            TreeNode* curr = nullptr;

            auto add = [&new_root, &curr](TreeNode* n) {
                if (!new_root)
                {
                    new_root = n;
                    new_root->left = new_root->right = nullptr;
                    curr = new_root;
                }
                else
                {
                    curr->right = n;
                    curr = n;
                    curr->left = curr->right = nullptr;
                }
            };

            go_left(root);

            while (!nodes.empty())
            {
                auto* to_add = nodes.top();
                nodes.pop();
                go_left(to_add->right);

                add(to_add);
            }

            return new_root;
        }
    };
}
