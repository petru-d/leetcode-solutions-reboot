#pragma once
#include "util_binary_tree.h"
#include <vector>

namespace p1305
{
    class Solution
    {
        // can also do a non recursive peorder traversal that keeps a stack
      public:
        std::vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
        {
            std::vector<int> els1;
            go(root1, els1);
            std::vector<int> els2;
            go(root2, els2);

            std::vector<int> result;
            result.reserve(els1.size() + els2.size());

            auto E1 = els1.size();
            auto E2 = els2.size();

            size_t i1 = 0;
            size_t i2 = 0;
            while (i1 < E1 || i2 < E2)
            {
                if (i1 == E1)
                {
                    result.push_back(els2[i2++]);
                    continue;
                }
                if (i2 == E2)
                {
                    result.push_back(els1[i1++]);
                    continue;
                }

                if (els1[i1] < els2[i2])
                    result.push_back(els1[i1++]);
                else
                    result.push_back(els2[i2++]);
            }

            return result;
        }

      private:
        void go(TreeNode* root, std::vector<int>& res)
        {
            if (root == nullptr)
                return;

            go(root->left, res);
            res.push_back(root->val);
            go(root->right, res);
        }
    };

}
