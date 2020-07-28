#pragma once
#include "util_binary_tree.h"
#include <algorithm>
#include <vector>

namespace p106
{
    class Solution
    {
      public:
        TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder)
        {
            return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
        }

        TreeNode* buildTree(std::vector<int>::iterator startInorder, std::vector<int>::iterator endInorder,
                            std::vector<int>::iterator startPostorder, std::vector<int>::iterator endPostorder)
        {
            if (startInorder == endInorder)
                return nullptr;

            if (std::next(startInorder) == endInorder)
                return new TreeNode(*startInorder);

            auto* root = new TreeNode(*std::prev(endPostorder));

            auto rootPosInorder = std::find(startInorder, endInorder, *std::prev(endPostorder));

            size_t left_len = std::distance(startInorder, rootPosInorder);

            auto* leftTree = buildTree(startInorder, startInorder + left_len, startPostorder, startPostorder + left_len);

            auto* rightTree =
                buildTree(std::next(rootPosInorder), endInorder, startPostorder + left_len, std::prev(endPostorder));

            root->left = leftTree;
            root->right = rightTree;

            return root;
        }
    };
}
