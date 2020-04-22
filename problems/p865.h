#pragma once
#include "util_binary_tree.h"
#include <unordered_map>
#include <unordered_set>

namespace p865
{
    class Solution
    {
      public:
        TreeNode* subtreeWithAllDeepest(TreeNode* root)
        {
            if (root == nullptr)
                return nullptr;

            _deepest = 0;
            _parents.insert({root, nullptr});
            find_deepest(root, 0);

            // since they are at the same depth, increasing each time one level will end us in the common root
            while (_deepest_nodes.size() > 1)
            {
                std::unordered_set<TreeNode*> next_level;
                for (const auto& n : _deepest_nodes)
                    next_level.insert(_parents[n]);

                _deepest_nodes = std::move(next_level);
            }

            return *_deepest_nodes.begin();
        }

      private:
        void find_deepest(TreeNode* root, size_t current_depth)
        {
            if (current_depth > _deepest)
            {
                _deepest_nodes = {root};
                _deepest = current_depth;
            }
            else if (current_depth == _deepest)
            {
                _deepest_nodes.insert(root);
            }

            if (root->left != nullptr)
            {
                _parents.insert({root->left, root});
                find_deepest(root->left, current_depth + 1);
            }
            if (root->right != nullptr)
            {
                _parents.insert({root->right, root});
                find_deepest(root->right, current_depth + 1);
            }
        }

        std::unordered_set<TreeNode*> _deepest_nodes;
        std::unordered_map<TreeNode*, TreeNode*> _parents;
        size_t _deepest;
    };
}