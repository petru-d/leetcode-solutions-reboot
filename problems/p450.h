#pragma once

#include "util_binary_tree.h"

namespace p450
{
    class Solution
    {
      public:
        TreeNode* deleteNode(TreeNode* root, int key)
        {
            if (nullptr == root)
                return nullptr;

            auto [parent, node] = search(nullptr, root, key);
            if (node == nullptr)
                return root;

            // either right or left subtree are missing - it is safe to simply elliminate the node
            if (node->right == nullptr || node->left == nullptr)
            {
                auto* newNode = elliminate(parent, node);
                if (parent == nullptr)
                    root = newNode;
                return root;
            }

            // search for the node with the lowest value from the node's right subtree <mini>
            // this <mini>'s value will be the new value of <node>
            // then we elliminate <mini>, which is safe since mini doesn't have a left subtree
            auto [miniparent, mini] = searchmin(node, node->right);
            node->val = mini->val;
            elliminate(miniparent, mini);
            return root;
        }

      private:
        // search for a node with a given key, return its parent and the node itself
        std::pair<TreeNode*, TreeNode*> search(TreeNode* parent, TreeNode* current, int key)
        {
            if (nullptr == current)
                return {nullptr, nullptr};
            if (current->val == key)
                return {parent, current};

            if (current->val < key)
                return search(current, current->right, key);

            return search(current, current->left, key);
        }

        // the node and its non-null subtree (if any) are discarded
        // the parent's new child will be the non-null subtree of the node (if any)
        // we return the new node that took <node>'s place
        TreeNode* elliminate(TreeNode* parent, TreeNode* node)
        {
            assert(node->left == nullptr || node->right == nullptr);

            auto* newNode = node->left ? node->left : node->right;

            if (parent)
            {
                bool left = (parent->left == node);

                if (left)
                    parent->left = newNode;
                else
                    parent->right = newNode;
            }
            delete node;
            return newNode;
        }

        // search for the node with the lowest value starting at a current position
        // this is obtained by going left as much as possible.
        std::pair<TreeNode*, TreeNode*> searchmin(TreeNode* parent, TreeNode* current)
        {
            if (current->left == nullptr)
                return {parent, current};

            return searchmin(current, current->left);
        }
    };
}
