#pragma once

#include "util_binary_tree.h"

namespace p938
{
    class Solution
    {
      public:
        int rangeSumBST(TreeNode* root, int L, int R)
        {
            auto in_range_or_nothing = [](int val, int L, int R) { return (L <= val && val <= R) ? val : 0; };

            if (root == nullptr)
                return 0;

            bool explore_right = true;
            bool explore_left = true;

            // everything left of root is guaranteed (strictly) less than root
            if (root->val <= L)
                explore_left = false;

            // everything left of root is guaranteed (strictly) greater than root
            if (root->val >= R)
                explore_right = false;

            explore_left &= (nullptr != root->left);
            explore_right &= (nullptr != root->right);

            int left_sum = explore_left ? rangeSumBST(root->left, L, R) : 0;
            int right_sum = explore_right ? rangeSumBST(root->right, L, R) : 0;

            return left_sum + right_sum + in_range_or_nothing(root->val, L, R);
        }
    };
}