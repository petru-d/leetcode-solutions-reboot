#pragma once
#include "util_binary_tree.h"

namespace p285
{
    class Solution2
    {
      public:
        TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
        {
            TreeNode* target = nullptr;
            bool exiting = false;
            go(root, nullptr, p, target, exiting);

            return target;
        }

        void go(TreeNode* current, TreeNode* parent, TreeNode* p, TreeNode*& target, bool& exiting)
        {
            if (!current)
                return;

            if (current == p)
            {
                if (p->right)
                    target = p->right;
                while (target && target->left)
                    target = target->left;
                exiting = true;
                return;
            }

            go(current->left, current, p, target, exiting);
            if (exiting)
            {
                if (current->val > p->val && !target)
                    target = current;
            }

            go(current->right, current, p, target, exiting);
            if (exiting)
            {
                if (current->val > p->val && !target)
                    target = current;
            }
        }
    };

    class Solution
    {
      public:
        TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
        {
            _p = p;

            go(root);
            return _successor;
        }

        TreeNode* _p = nullptr;
        TreeNode* _successor = nullptr;
        bool _found_p = false;
        bool _found_successor = false;

        void go(TreeNode* current)
        {
            if (!current)
                return;

            go(current->left);

            process(current);

            go(current->right);
        }

        void process(TreeNode* n)
        {
            if (n == _p)
            {
                _found_p = true;
                return;
            }

            if (_found_p && !_found_successor)
            {
                _successor = n;
                _found_successor = true;
            }
        }
    };
}
