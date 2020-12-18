#pragma once
#include "util_binary_tree.h"

#include <unordered_map>

namespace p337
{
    class Solution
    {
      public:
        int rob(TreeNode* root)
        {
            go(root);

            return _value[root];
        }

      private:
        void go(TreeNode* root)
        {
            if (nullptr == root)
                return;

            go(root->left);
            go(root->right);

            int level_one = 0;
            int level_two = 0;
            if (root->left)
            {
                level_one += _value[root->left];
                if (root->left->left)
                    level_two += _value[root->left->left];
                if (root->left->right)
                    level_two += _value[root->left->right];
            }
            if (root->right)
            {
                level_one += _value[root->right];
                if (root->right->left)
                    level_two += _value[root->right->left];
                if (root->right->right)
                    level_two += _value[root->right->right];
            }

            _value[root] = std::max(root->val + level_two, level_one);
        }

        std::unordered_map<TreeNode*, int> _value;
    };
}
