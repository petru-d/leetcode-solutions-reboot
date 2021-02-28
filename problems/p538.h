#pragma once

#include "util_binary_tree.h"

namespace p538
{

    class Solution
    {
      public:
        TreeNode* convertBST(TreeNode* root)
        {
            if (root == nullptr)
                return root;

            go(root, 0);
            return root;
        }

        // return sum of left subtree, add to root sum of right subtree
        int go(TreeNode* root, int v)
        {
            if (nullptr == root)
                return v;

            root->val += go(root->right, v);

            return go(root->left, root->val);
        }
    };
}

/* another solution
class Solution {
public:
    TreeNode* convertBST(TreeNode* root)
    {
        convert(root, 0);
        return root;
    }

    int convert(TreeNode* root, int incoming)
    {
        if (!root)
            return incoming;

        int right_res = convert(root->right, incoming);
        root->val += right_res;
        return convert(root->left, root->val);
    }
};

*/