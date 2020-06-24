#pragma once

#include "util_binary_tree.h"

namespace p563
{

    class Solution
    {
      public:
        int findTilt(TreeNode* root)
        {
            int totalTilt = 0;
            sum(root, totalTilt);
            return totalTilt;
        }

        int sum(TreeNode* root, int& totalTilt)
        {
            if (root == nullptr)
                return 0;

            int leftSum = sum(root->left, totalTilt);
            int rightSum = sum(root->right, totalTilt);

            totalTilt += std::abs(leftSum - rightSum);

            return leftSum + rightSum + root->val;
        }
    };
}
