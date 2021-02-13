#pragma once
#include "util_binary_tree.h"
#include <array>

namespace p1457
{
    class Solution
    {
      public:
        int pseudoPalindromicPaths(TreeNode* root)
        {
            if (!root)
                return 0;

            std::array<size_t, 10> h = {};
            int result = 0;
            go(root, h, result);
            return result;
        }

        void go(TreeNode* root, std::array<size_t, 10>& h, int& result)
        {
            ++h[size_t(root->val)];

            if (!root->left && !root->right && ppali(h))
                ++result;

            if (root->left)
                go(root->left, h, result);
            if (root->right)
                go(root->right, h, result);

            --h[size_t(root->val)];
        }

        bool ppali(const std::array<size_t, 10>& h)
        {
            auto c = std::count_if(h.begin(), h.end(), [](size_t i) { return i % 2 == 1; });
            return c <= 1;
        }
    };
}
