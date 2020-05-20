#pragma once
#include "util_binary_tree.h"

namespace p230
{

    class Solution
    {
      public:
        int kthSmallest(TreeNode* root, int k)
        {
            _count = 0;

            descend(root, k);

            return _answer;
        }

      private:
        void descend(TreeNode* root, int k)
        {
            if (_count < k && root->left)
                descend(root->left, k);

            ++_count;
            if (_count == k)
                _answer = root->val;

            if (_count < k && root->right)
                descend(root->right, k);
        }

        int _count = 0;
        int _answer = 0;
    };
}