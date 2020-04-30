#pragma once
#include "util_binary_tree.h"
#include <vector>

namespace challenge_30apr2020
{
    class Solution
    {
      public:
        bool isValidSequence(TreeNode* root, std::vector<int>& arr)
        {
            if (arr.empty())
                return true;

            if (root == nullptr)
                return false;

            return rec(root, arr, 0);
        }

      private:
        bool rec(TreeNode* root, const std::vector<int>& arr, size_t index)
        {
            if (index >= arr.size())
                return false;
            if (root->val != arr[index])
                return false;

            if (root->left == nullptr && root->right == nullptr && index == arr.size() - 1)
                return true;

            bool left_ok = root->left ? rec(root->left, arr, index + 1) : false;
            if (left_ok)
                return true;
            return (root->right ? rec(root->right, arr, index + 1) : false);
        }
    };
}