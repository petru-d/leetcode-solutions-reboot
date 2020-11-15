#pragma once

#include "util_binary_tree.h"

#include <algorithm>
#include <queue>
#include <stack>
#include <vector>

//can also be done in o(1) if using in order morris traversal

namespace p99
{
    class Solution
    {
      public:
        void recoverTree2(TreeNode* root)
        {
            std::vector<int> values;

            std::stack<TreeNode*> nodes;

            auto push_left = [&nodes](TreeNode* root) {
                while (root != nullptr)
                {
                    nodes.push(root);
                    root = root->left;
                }
            };

            push_left(root);
            while (!nodes.empty())
            {
                auto* top = nodes.top();
                values.push_back(top->val);
                nodes.pop();
                push_left(top->right);
            }

            std::sort(values.begin(), values.end());

            size_t curr = 0;
            push_left(root);
            while (!nodes.empty())
            {
                auto* top = nodes.top();
                top->val = values[curr++];
                nodes.pop();
                push_left(top->right);
            }
        }

        void recoverTree(TreeNode* root)
        {
            if (nullptr == root)
                return;

            std::stack<TreeNode*> nodes;
            auto push_left = [&nodes](TreeNode* root) {
                while (root != nullptr)
                {
                    nodes.push(root);
                    root = root->left;
                }
            };

            TreeNode* critical1 = nullptr;
            TreeNode* critical2 = nullptr;

            int prev_val = std::numeric_limits<int>::min();
            TreeNode* prev_node = nullptr;

            push_left(root);
            while (!nodes.empty())
            {
                auto* top = nodes.top();

                if (prev_node && top->val < prev_val)
                {
                    if (!critical1)
                    {
                        critical1 = prev_node;
                        critical2 = top;
                    }
                    else
                    {
                        critical2 = top;
                        break;
                    }
                }
                
                
                prev_node = top;
                prev_val = top->val;

                nodes.pop();
                push_left(top->right);
            }

            if (critical1 && critical2)
                std::swap(critical1->val, critical2->val);
        }
    };
}
