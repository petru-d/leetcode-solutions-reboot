#pragma once

#include "util_binary_tree.h"
#include <string>

namespace p606
{

    class Solution
    {
      public:
        std::string tree2str(TreeNode* t)
        {
            if (nullptr == t)
                return "";
            std::string tree;
            make(t, tree);
            return tree;
        }

      private:
        void make(TreeNode* t, std::string& tree)
        {
            if (t->left == nullptr && t->right == nullptr)
            {
                tree += std::to_string(t->val);
                return;
            }

            tree += std::to_string(t->val);

            tree += "(";
            if (t->left)
                make(t->left, tree);
            tree += ")";

            if (t->right)
            {
                tree += "(";
                make(t->right, tree);
                tree += ")";
            }
        }
    };
}
