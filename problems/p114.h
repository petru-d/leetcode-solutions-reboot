#pragma once
#include "util_binary_tree.h"

namespace p114
{
    class Solution
    {
      public:
        void flatten(TreeNode* root)
        {
            if (!root)
                return;

            flatten_get_last(root);
        }

        TreeNode* flatten_get_last(TreeNode* root)
        {
            if (!root->left && !root->right)
                return root;

            if (!root->left)
                return flatten_get_last(root->right);

            if (!root->right)
            {
                root->right = root->left;
                root->left = nullptr;

                return flatten_get_last(root->right);
            }

            auto* first_left = root->left;
            auto* first_right = root->right;
            auto* last_left = flatten_get_last(root->left);
            auto* last_right = flatten_get_last(root->right);

            root->left = nullptr;
            root->right = first_left;
            last_left->left = nullptr;
            last_left->right = first_right;
            first_right->left = nullptr;

            return last_right;
        }
    };

    class Solution2
    {
      public:
        void flatten(TreeNode* root)
        {
            auto* curr = root;
            while (curr)
            {
                if (!curr->left)
                {
                    curr = curr->right;
                    continue;
                }

                auto* rightmost_of_left = curr->left;
                while (rightmost_of_left->right)
                    rightmost_of_left = rightmost_of_left->right;

                auto* old_left = curr->left;
                auto* old_right = curr->right;

                curr->left = nullptr;
                curr->right = old_left;
                rightmost_of_left->right = old_right;

                curr = curr->right;
            }
        }
    };
}
