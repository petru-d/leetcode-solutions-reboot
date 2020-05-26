#pragma once
#include "util_binary_tree.h"
#include <cassert>
#include <stack>
#include <vector>

namespace p1008
{
    class Solution
    {
      public:
        TreeNode* bstFromPreorder2(std::vector<int>& preorder)
        {
            if (preorder.empty())
                return nullptr;

            auto* root = new TreeNode(preorder.front());
            std::vector<TreeNode*> path;
            path.push_back(root);

            for (size_t i = 1; i < preorder.size(); ++i)
            {
                assert(!path.empty());

                auto* curr = new TreeNode(preorder[i]);

                if (preorder[i] < path.back()->val)
                {
                    path.back()->left = curr;
                    path.push_back(curr);
                }
                else
                {
                    // find where to insert the current element - first open position in a right while respecting bst format
                    std::vector<TreeNode*> new_path = {root};
                    while (true)
                    {
                        if (new_path.back()->val < preorder[i] && new_path.back()->right == nullptr)
                        {
                            new_path.back()->right = curr;
                            new_path.push_back(curr);
                            break;
                        }
                        else if (new_path.back()->val > preorder[i])
                        {
                            assert(new_path.back()->left);
                            new_path.push_back(new_path.back()->left);
                        }
                        else
                        {
                            assert(new_path.back()->right);
                            new_path.push_back(new_path.back()->right);
                        }
                    }

                    path = std::move(new_path);
                }
            }

            return root;
        }

        TreeNode* bstFromPreorder(std::vector<int>& preorder)
        {
            size_t index = 0;
            auto* root = build(std::numeric_limits<int>::max(), preorder, index);

            return root;
        }

        TreeNode* build(int root_val, const std::vector<int>& preorder, size_t& next_index)
        {
            if (next_index >= preorder.size() || preorder[next_index] >= root_val)
                return nullptr;

            auto* newNode = new TreeNode(preorder[next_index]);

            ++next_index;

            newNode->left = build(newNode->val, preorder, next_index);
            newNode->right = build(root_val, preorder, next_index);

            return newNode;
        }
    };

}