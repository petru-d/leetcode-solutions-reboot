#pragma once
#include "util_binary_tree.h"
namespace p536
{
    class Solution
    {
      public:
        TreeNode* str2tree(std::string s)
        {
            if (s.empty())
                return nullptr;
            return makeTree(s, 0).first;
        }

        std::pair<TreeNode*, size_t> makeTree(const std::string& s, size_t pos)
        {
            // val(left)(right)
            //    l    Lr     R
            // left: make(val_end + 1) -> {l*, L}

            auto end_val = pos + 1;
            while (end_val < s.size() && s[end_val] != '(' && s[end_val] != ')')
                ++end_val;

            int val = 0;
            std::from_chars(s.data() + pos, s.data() + end_val, val);

            auto* result = new TreeNode(val);
            if (end_val >= s.size() || ')' == s[end_val])
                return {result, end_val};

            auto [left_tree, left_end] = makeTree(s, end_val + 1);
            result->left = left_tree;
            if (left_end + 1 >= s.size() || s[left_end + 1] != '(')
                return {result, left_end + 1};

            auto [right_tree, right_end] = makeTree(s, left_end + 2);
            result->right = right_tree;
            return {result, right_end + 1};
        }
    };
}
