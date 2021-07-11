#pragma once

#include "util_binary_tree.h"
#include <unordered_map>
#include <vector>

namespace p105
{
    /**
     * Definition for a binary tree node.
     * struct TreeNode {
     *     int val;
     *     TreeNode *left;
     *     TreeNode *right;
     *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     * };
     */
    class Solution
    {
      public:
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
        {
            _preorder = std::move(preorder);
            _inorder = std::move(inorder);
            auto S = _preorder.size();
            for (size_t i = 0; i < S; ++i)
            {
                _positions[_preorder[i]].PreorderIndex = i;
                _positions[_inorder[i]].InorderIndex = i;
            }

            return make_tree(0, S, 0, S);
        }

        TreeNode* make_tree(size_t beginPre, size_t endPre, size_t beginIn, size_t endIn)
        {
            if (beginPre >= endPre || beginIn >= endIn)
                return nullptr;

            auto posRootInorder = _positions[_preorder[beginPre]].InorderIndex;

            auto lenLeftTree = posRootInorder - beginIn;
            auto lenRightTree = endIn - posRootInorder;

            auto* rootNode = new TreeNode(_preorder[beginPre]);
            rootNode->left = make_tree(beginPre + 1, beginPre + 1 + lenLeftTree, beginIn, posRootInorder);
            rootNode->right = make_tree(beginPre + 1 + lenLeftTree, endPre, posRootInorder + 1, endIn);

            return rootNode;
        }

      private:
        std::vector<int> _preorder;
        std::vector<int> _inorder;
        struct Position
        {
            size_t PreorderIndex = -1;
            size_t InorderIndex = -1;
        };
        std::unordered_map<int, Position> _positions;
    };
}
