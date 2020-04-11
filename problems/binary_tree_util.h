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

TreeNode* make_binary_tree(int root_val)
{
    return new TreeNode(root_val);
}

TreeNode* make_binary_tree(TreeNode* l, int root_val)
{
    auto* root = new TreeNode(root_val);
    root->left = l;
    return root;
}

TreeNode* make_binary_tree(int root_val, TreeNode* r)
{
    auto* root = new TreeNode(root_val);
    root->right = r;
    return root;
}

TreeNode* make_binary_tree(TreeNode* l, int root_val, TreeNode* r)
{
    auto* root = new TreeNode(root_val);
    root->left = l;
    root->right = r;
    return root;
}