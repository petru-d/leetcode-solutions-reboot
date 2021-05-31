#pragma once
#include "util_binary_tree.h"
#include <vector>

namespace p102
{
    class Solution2
    {
      public:
        std::vector<std::vector<int>> levelOrder(TreeNode* root)
        {
            if (!root)
                return {};

            std::vector<std::vector<int>> result;

            std::vector<TreeNode*> currLevel = {root};
            while (!currLevel.empty())
            {
                std::vector<TreeNode*> nextLevel;
                std::vector<int> resLvl;
                for (const auto* n : currLevel)
                {
                    resLvl.push_back(n->val);
                    if (n->left)
                        nextLevel.push_back(n->left);
                    if (n->right)
                        nextLevel.push_back(n->right);
                }
                result.push_back(std::move(resLvl));
                std::swap(currLevel, nextLevel);
            }

            return result;
        }
    };

    class Solution
    {
      public:
        std::vector<std::vector<int>> levelOrder(TreeNode* root)
        {
            std::vector<std::vector<int>> result;
            dfs(root, 0, result);
            return result;
        }

        void dfs(TreeNode* root, size_t level, std::vector<std::vector<int>>& result)
        {
            if (!root)
                return;

            if (level >= result.size())
                result.push_back({});

            result[level].push_back(root->val);

            dfs(root->left, level + 1, result);
            dfs(root->right, level + 1, result);
        }
    };
}
