#pragma once
#include "util_binary_tree.h"

namespace p98
{
    class Solution
    {
      public:
        bool isValidBST(TreeNode* root)
        {
            if (!root)
                return true;

            auto [min, max, valid] = checkTree(root);
            return valid;
        }

        struct TreeCheckResult
        {
            int Min = std::numeric_limits<int>::max();
            int Max = std::numeric_limits<int>::min();
            bool Valid = false;
        };

        TreeCheckResult checkTree(TreeNode* root)
        {
            TreeCheckResult res{root->val, root->val, true};

            if (root->left)
            {
                auto leftRes = checkTree(root->left);
                res.Valid = (res.Valid && leftRes.Valid && root->val > leftRes.Max);
                res.Min = std::min(res.Min, leftRes.Min);
                res.Max = std::max(res.Max, leftRes.Max);
            }
            if (!res.Valid)
                return res;

            if (root->right)
            {
                auto rightRes = checkTree(root->right);
                res.Valid = (res.Valid && rightRes.Valid && root->val < rightRes.Min);
                res.Min = std::min(res.Min, rightRes.Min);
                res.Max = std::max(res.Max, rightRes.Max);
            }
            return res;
        }
    };
}
