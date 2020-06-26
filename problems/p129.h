#pragma once
#include "util_binary_tree.h"

namespace p129
{
    class Solution
    {
      public:
        int sumNumbers(TreeNode* root)
        {
            if (nullptr != root)
            {
                gather(root, 0);
            }
            return _total;
        }

      private:
        void gather(TreeNode* root, int up)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                _total += 10 * up + root->val;
                return;
            }
            if (root->left != nullptr)
            {
                gather(root->left, 10 * up + root->val);
            }
            if (root->right != nullptr)
            {
                gather(root->right, 10 * up + root->val);
            }
        }

        int _total = 0;
    };
}
