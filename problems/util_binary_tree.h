#pragma once

#include <optional>
#include <vector>

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

inline std::vector<std::optional<int>> to_vector_levelwise_full(TreeNode* root)
{
    if (root == nullptr)
        return {};

    std::vector<std::vector<TreeNode*>> rows = {{root}};

    while (true)
    {
        const auto& last_row = rows.back();

        bool found_non_null = false;
        std::vector<TreeNode*> new_row;
        for (auto* node : last_row)
        {
            if (nullptr == node)
            {
                new_row.push_back(nullptr);
                new_row.push_back(nullptr);
            }
            else
            {
                if (node->left != nullptr || node->right != nullptr)
                    found_non_null = true;
                new_row.push_back(node->left);
                new_row.push_back(node->right);
            }
        }

        if (!found_non_null)
            break;

        rows.emplace_back(std::move(new_row));
    }

    std::vector<std::optional<int>> result;
    for (const auto& row : rows)
        for (const auto* node : row)
            result.push_back(node != nullptr ? node->val : std::optional<int>());

    return result;
}