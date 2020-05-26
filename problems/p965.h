#pragma once
#include "util_binary_tree.h"

namespace p965
{
    class Solution
    {
      public:
        bool isUnivalTree(TreeNode* root)
        {
            if (root == nullptr)
                return true;

            return isUnivalTree(root, root->val);
        }

      private:
        bool isUnivalTree(TreeNode* root, int val)
        {
            if (root == nullptr)
                return true;
            if (root->val != val)
                return false;

            bool leftOk = isUnivalTree(root->left, val);
            if (!leftOk)
                return false;

            return isUnivalTree(root->right, val);
        }
    };
}