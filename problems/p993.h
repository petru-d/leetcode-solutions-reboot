#pragma once
#include "util_binary_tree.h"
#
namespace p993
{

    class Solution
    {
      public:
        struct NodeInfo
        {
            int SeekVal = -1;
            bool Found = false;
            int Level = -1;
            TreeNode* Parent = nullptr;
        };

        bool isCousins(TreeNode* root, int x, int y)
        {
            NodeInfo x_info{x, false, -1, nullptr};
            NodeInfo y_info{y, false, -1, nullptr};
            go(root, 0, x_info, y_info);

            return x_info.Level == y_info.Level && x_info.Parent != y_info.Parent;
        }

      private:
        void go(TreeNode* root, int level, NodeInfo& x_info, NodeInfo& y_info)
        {
            if (root == nullptr || (x_info.Found && y_info.Found))
                return;

            if (root->left != nullptr)
            {
                if (root->left->val == x_info.SeekVal)
                {
                    x_info.Found = true;
                    x_info.Parent = root;
                    x_info.Level = level + 1;
                }
                if (!y_info.Found)
                {
                    go(root->left, level + 1, x_info, y_info);
                }
                if (root->left->val == y_info.SeekVal)
                {
                    y_info.Found = true;
                    y_info.Parent = root;
                    y_info.Level = level + 1;
                }
                if (!x_info.Found)
                {
                    go(root->left, level + 1, x_info, y_info);
                }
            }
            if (root->right != nullptr)
            {
                if (root->right->val == x_info.SeekVal)
                {
                    x_info.Found = true;
                    x_info.Parent = root;
                    x_info.Level = level + 1;
                }
                if (!y_info.Found)
                {
                    go(root->right, level + 1, x_info, y_info);
                }
                if (root->right->val == y_info.SeekVal)
                {
                    y_info.Found = true;
                    y_info.Parent = root;
                    y_info.Level = level + 1;
                }
                if (!x_info.Found)
                {
                    go(root->right, level + 1, x_info, y_info);
                }
            }
        }
    };
}