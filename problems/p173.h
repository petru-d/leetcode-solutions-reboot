#pragma once
#include "util_binary_tree.h"
#include <stack>

namespace p173
{
    class BSTIterator
    {
      public:
        BSTIterator(TreeNode* root)
        {
            pushLeft(root);
        }

        int next()
        {
            auto* top = _nodes.top();
            _nodes.pop();
            pushLeft(top->right);

            return top->val;
        }

        bool hasNext()
        {
            return !_nodes.empty();
        }

      private:
        void pushLeft(TreeNode* root)
        {
            while (root)
            {
                _nodes.push(root);
                root = root->left;
            }
        }

        std::stack<TreeNode*> _nodes;
    };
}
