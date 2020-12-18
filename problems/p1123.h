#pragma once
#include "util_binary_tree.h"
#include <unordered_map>
namespace p1123
{
    class Solution
    {
      public:
        TreeNode* lcaDeepestLeaves(TreeNode* root)
        {
            if (!root)
                return nullptr;

            auto depth = build_map(root, 0);

            return search(root, depth);
        }

        TreeNode* search(TreeNode* root, int depth)
        {
            if (!root->left && !root->right)
                return root;

            if (!root->left)
                return search(root->right, depth);

            if (!root->right)
                return search(root->left, depth);

            auto depth_left = _subtreeDepthMap[root->left];
            auto depth_right = _subtreeDepthMap[root->right];

            if (depth_left == depth && depth_right == depth)
                return root;

            if (depth_left == depth)
                return search(root->left, depth);

            return search(root->right, depth);
        }

        int build_map(TreeNode* root, int curr_level)
        {
            if (!root)
                return 0;

            if (!root->left && !root->right)
            {
                _subtreeDepthMap[root] = curr_level;
                return curr_level;
            }

            int left_depth = build_map(root->left, curr_level + 1);
            int right_depth = build_map(root->right, curr_level + 1);

            auto depth = std::max(left_depth, right_depth);

            _subtreeDepthMap[root] = depth;
            return depth;
        }

        // max depth of nodes in the subtree at the node
        std::unordered_map<TreeNode*, int> _subtreeDepthMap;
    };
}
