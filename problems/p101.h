#pragma once

#include "util_binary_tree.h"

namespace p101
{

    class Solution
    {
      public:
        bool isSymmetric(TreeNode* root)
        {
            if (nullptr == root)
                return true;
            return eq_mirror(root->left, root->right);
        }

        bool eq_mirror(TreeNode* l, TreeNode* r)
        {
            if (nullptr == l && nullptr == r)
                return true;

            if (nullptr == l || nullptr == r)
                return false;

            if (l->val != r->val)
                return false;

            bool ok = eq_mirror(l->left, r->right);
            if (!ok)
                return false;

            return eq_mirror(l->right, r->left);
        }
    };
}
