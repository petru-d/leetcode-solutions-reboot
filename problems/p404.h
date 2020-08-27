#pragma once

#include "util_binary_tree.h"

namespace p404
{

    class Solution
    {
      public:
        int sumOfLeftLeaves(TreeNode* root)
        {
            int sum = 0;
            go(nullptr, root, sum);
            return sum;
        }

      private:
        void go(TreeNode* parent, TreeNode* curr, int& sum)
        {
            if (nullptr == curr)
                return;

            // if leaf
            if (nullptr == curr->left && nullptr == curr->right)
            {
                if (nullptr != parent && parent->left == curr)
                    sum += curr->val;
                return;
            }
            go(curr, curr->left, sum);
            go(curr, curr->right, sum);
        }
    };
}
