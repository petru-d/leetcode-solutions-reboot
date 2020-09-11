#pragma once
#include "util_binary_tree.h"

namespace p1022
{

    class Solution
    {
      public:
        int sumRootToLeaf(TreeNode* root)
        {
            int sum = 0;
            go(root, 0, sum);
            return sum;
        }

      private:
        void go(TreeNode* curr, int incoming, int& sum)
        {
            if (curr == nullptr)
                return;

            if (nullptr == curr->left && nullptr == curr->right)
            {
                sum += 2 * incoming + curr->val;
                return;
            }
            go(curr->left, 2 * incoming + curr->val, sum);
            go(curr->right, 2 * incoming + curr->val, sum);
        }
    };
}
