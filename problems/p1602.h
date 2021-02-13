#pragma once
#include "util_binary_tree.h"

namespace p1602
{
    class Solution
    {
      public:
        TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u)
        {
            go(root, u, 0);

            return _u_next;
        }

        void go(TreeNode* root, TreeNode* u, int depth)
        {
            if (_u_next || (_u_depth != -1 && depth > _u_depth))
                return;

            if (root == u)
            {
                _u_depth = depth;
                return;
            }
            if (depth == _u_depth)
            {
                _u_next = root;
                return;
            }

            if (root->left && !_u_next)
                go(root->left, u, depth + 1);
            if (root->right && !_u_next)
                go(root->right, u, depth + 1);
        }

        int _u_depth = -1;
        TreeNode* _u_next = nullptr;
    };
}
