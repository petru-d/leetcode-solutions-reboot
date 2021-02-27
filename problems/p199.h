#pragma once
#include "util_binary_tree.h"
#include <queue>
#include <vector>
namespace p199
{
    class Solution
    {
      public:
        std::vector<int> rightSideView(TreeNode* root)
        {
            if (!root)
                return {};

            std::vector<int> view;
            std::deque<TreeNode*> line = {root};
            while (!line.empty())
            {
                view.push_back(line.back()->val);

                auto L = line.size();
                for (size_t i = 0; i < L; ++i)
                {
                    auto f = line.front();
                    if (f->left)
                        line.push_back(f->left);
                    if (f->right)
                        line.push_back(f->right);
                    line.pop_front();
                }
            }

            return view;
        }
    };
}
