#pragma once
#include "util_binary_tree.h"
#include <queue>
#include <vector>

namespace p637
{

    class Solution
    {
      public:
        std::vector<double> averageOfLevels(TreeNode* root)
        {
            std::vector<double> result;
            if (!root)
                return {};

            std::queue<TreeNode*> currLevel;
            currLevel.push(root);
            while (!currLevel.empty())
            {
                int64_t sum = 0;
                auto sz = currLevel.size();
                for (size_t i = 0; i < sz; ++i)
                {
                    auto* n = currLevel.front();
                    currLevel.pop();
                    sum += n->val;
                    if (n->left)
                        currLevel.push(n->left);
                    if (n->right)
                        currLevel.push(n->right);
                }
                result.push_back(double(sum) / sz);
            }

            return result;
        }
    };
}
