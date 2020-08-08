#pragma once
#include "util_binary_tree.h"

#include <unordered_map>

namespace p437
{
    class Solution
    {
      public:
        int pathSum(TreeNode* root, int sum)
        {
            std::unordered_map<int, int> m;
            int total = 0;
            helper(root, 0, sum, total, m);
            return total;
        }

      private:
        void helper(TreeNode* p, int cur, int sum, int& total, std::unordered_map<int, int>& m)
        {
            if (!p)
                return;

            cur += p->val;
            if (cur == sum)
                total++;

            auto pos = m.find(cur - sum);
            if (pos != m.end())
            {
                total += pos->second;
            }

            m[cur]++;

            helper(p->left, cur, sum, total, m);
            helper(p->right, cur, sum, total, m);

            m[cur]--;
        }
    };
}
