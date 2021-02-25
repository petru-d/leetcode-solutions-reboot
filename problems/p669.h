#pragma once
#include "util_binary_tree.h"

namespace p669
{
    class Solution
    {
      public:
        TreeNode* trimBST(TreeNode* root, int low, int high)
        {
            if (root->val < low)
            {
                auto* dummy = new TreeNode(low);
                dummy->left = root;
                fix(dummy->left, dummy, true, low, high);
                return dummy->left;
            }

            if (root->val > high)
            {
                auto* dummy = new TreeNode(high);
                dummy->right = root;
                fix(dummy->right, dummy, false, low, high);
                return dummy->right;
            }

            auto* dummy = new TreeNode(low - 1);
            dummy->right = root;
            fix(dummy->right, dummy, false, low, high);
            return dummy->right;
        }

        TreeNode* fix(TreeNode* root, TreeNode* parent, bool left, int low, int high)
        {
            if (!root)
                return nullptr;

            if (root->val < low)
            {
                if (left)
                {
                    parent->left = fix(root->right, root, false, low, high);
                    return parent->left;
                }

                parent->right = fix(root->right, root, false, low, high);
                return parent->right;
            }

            if (root->val > high)
            {
                if (left)
                {
                    parent->left = fix(root->left, root, true, low, high);
                    return parent->left;
                }

                parent->right = fix(root->left, root, true, low, high);
                return parent->right;
            }

            root->left = fix(root->left, root, true, low, high);
            root->right = fix(root->right, root, false, low, high);
            return root;
        }
    };
}
