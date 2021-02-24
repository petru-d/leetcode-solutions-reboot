#pragma once
#include "util_binary_tree.h"

namespace p112
{
    class Solution
    {
      public:
        bool hasPathSum(TreeNode* root, int targetSum)
        {
            if (!root)
                return targetSum == 0;
            bool leftOk = false;
            if (root->left)
                leftOk = hasPathSum(root->left, targetSum - root->val);
            if (leftOk)
                return true;
            if (root->right)
                return hasPathSum(root->right, targetSum - root->val);

            // asymmetry to check the case with only one node: root->right cannot exist (we would have returned)
            // then the node is ok iff left is also missing AND the value of the node is the target
            return !root->left && root->val == targetSum;
        }
    };
}
