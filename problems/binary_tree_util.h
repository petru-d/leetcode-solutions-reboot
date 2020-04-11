#pragma once

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
};

inline TreeNode* make_binary_tree(int root_val)
{
    return new TreeNode(root_val);
}

inline TreeNode* make_binary_tree(TreeNode* l, int root_val)
{
    auto* root = new TreeNode(root_val);
    root->left = l;
    return root;
}

inline TreeNode* make_binary_tree(int root_val, TreeNode* r)
{
    auto* root = new TreeNode(root_val);
    root->right = r;
    return root;
}

inline TreeNode* make_binary_tree(TreeNode* l, int root_val, TreeNode* r)
{
    auto* root = new TreeNode(root_val);
    root->left = l;
    root->right = r;
    return root;
}

inline TreeNode* make_binary_tree(int l_val, int root_val, int r_val)
{
    auto* root = new TreeNode(root_val);
    auto* left = new TreeNode(l_val);
    auto* right = new TreeNode(r_val);
    root->left = left;
    root->right = right;
    return root;
}
