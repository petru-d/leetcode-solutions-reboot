#pragma once
#include "util_binary_tree.h"

namespace p100
{
    class Solution
    {
      public:
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            if (p == nullptr)
                return q == nullptr;
            if (q == nullptr)
                return false;

            if (p->val != q->val)
                return false;

            bool leftEq = isSameTree(p->left, q->left);
            if (!leftEq)
                return false;

            return isSameTree(p->right, q->right);
        }
    };
}