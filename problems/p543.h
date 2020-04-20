#pragma once

#include "util_binary_tree.h"
#include <algorithm>

namespace p543
{
    class Solution
    {
      public:
        /*
        int diameterOfBinaryTree(TreeNode* root)
        {
            if (root == nullptr)
                return 0;

            int through_root = 0;
            if (nullptr != root->left)
                through_root += 1 + height(root->left);
            if (nullptr != root->right)
                through_root += 1 + height(root->right);

            int left_dia = diameterOfBinaryTree(root->left);
            int right_dia = diameterOfBinaryTree(root->right);

            return std::max({through_root, left_dia, right_dia}, [](int l, int r) { return l < r; });
        }

        int height(TreeNode* root)
        {
            if (root == nullptr || (root->left == nullptr && root->right == nullptr))
                return 0;

            return 1 + std::max(height(root->left), height(root->right));
        }*/

        int diameterOfBinaryTree(TreeNode* root)
        {
            return dia_and_height(root).first;
        }

        std::pair<int, int> dia_and_height(TreeNode* root)
        {
            if (root == nullptr || (root->left == nullptr && root->right == nullptr))
                return {0, 0};

            auto [left_dia, left_height] = dia_and_height(root->left);
            auto [right_dia, right_height] = dia_and_height(root->right);

            int through_root = 0;
            if (nullptr != root->left)
                through_root += 1 + left_height;
            if (nullptr != root->right)
                through_root += 1 + right_height;

            int dia = std::max({through_root, left_dia, right_dia}, [](int l, int r) { return l < r; });

            int height = 1 + std::max(left_height, right_height);

            return {dia, height};
        }
    };
}