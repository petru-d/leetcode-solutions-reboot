#pragma once

#include "util_binary_tree.h"
#include <algorithm>

namespace p124
{
    class Solution
    {
      public:
        int maxPathSum(TreeNode* root)
        {
            best_for_node(root);

            return _max;
        }

      private:
        int best_for_node(TreeNode* root)
        {
            // Do we have a left (or right) subtree? if yes, is it positive? Then keep, otherwise ignore.
            int l = (root->left) ? std::max(best_for_node(root->left), 0) : 0;
            int r = (root->right) ? std::max(best_for_node(root->right), 0) : 0;

            // The best path through the current node is the current node's value plus the best paths till the left and the right
            // children (if not ignored).
            int through_root = root->val + l + r;
            _max = std::max(_max, through_root);

            // Return only the best path UNTIL (and including) this node (it will be used by the parent to calculate ITS best
            // path).
            return root->val + std::max(l, r);
        }

        int _max = std::numeric_limits<int>::min();
    };
}