#pragma once

#include <cassert>
#include <charconv>
#include <optional>
#include <string>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r)
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

inline bool equal_trees(TreeNode* l, TreeNode* r)
{
    if (l == nullptr)
        return r == nullptr;
    if (r == nullptr)
        return l == nullptr;

    bool mid_equal = l->val == r->val;
    if (!mid_equal)
        return false;

    bool l_equal = equal_trees(l->left, r->left);
    if (!l_equal)
        return false;

    return equal_trees(l->right, r->right);
}

inline void serialize_tree_helper(const TreeNode* root, std::string& buffer)
{
    if (nullptr == root)
        return;
    buffer.append(std::to_string(root->val));
    if (root->left == nullptr && root->right == nullptr)
        return;
    buffer += "(";

    if (root->left != nullptr)
        serialize_tree_helper(root->left, buffer);

    buffer += ",";

    if (root->right != nullptr)
        serialize_tree_helper(root->right, buffer);

    buffer += ")";
}

inline TreeNode* deserialize_tree_helper(const std::string& data, size_t& pos)
{
    auto get_num = [](const std::string& data, size_t& pos) {
        size_t end_pos = pos;
        while (end_pos < data.size() && (std::isdigit(data[end_pos]) || data[end_pos] == '-'))
            ++end_pos;

        int num = 0;
        [[maybe_unused]] auto [_, ec] = std::from_chars(data.data() + pos, data.data() + end_pos, num);
        assert(ec == std::errc());

        pos = end_pos;
        return num;
    };

    if (pos >= data.size() || (!std::isdigit(data[pos]) && data[pos] != '-'))
    {
        assert(false);
        return nullptr;
    }

    auto val = get_num(data, pos);

    auto* res = new TreeNode(val);
    if (pos >= data.size() || data[pos] != '(')
        return res;

    if (pos >= data.size() || data[pos] != '(')
    {
        assert(false);
        return res;
    }
    ++pos;

    bool have_left = data[pos] != ',';

    if (!have_left)
    {
        ++pos;
        res->right = deserialize_tree_helper(data, pos);
        assert(pos < data.size() && data[pos] == ')');
        ++pos;
        return res;
    }

    res->left = deserialize_tree_helper(data, pos);
    assert(pos < data.size() && data[pos] == ',');

    ++pos;
    assert(pos < data.size());
    if (data[pos] == ')')
    {
        ++pos;
        return res;
    }
    res->right = deserialize_tree_helper(data, pos);
    assert(pos < data.size() && data[pos] == ')');
    ++pos;
    return res;
}

inline std::string serialize_tree(TreeNode* root)
{
    std::string buffer;
    serialize_tree_helper(root, buffer);
    return buffer;
}

inline TreeNode* deserialize_tree(std::string data)
{
    if (data.empty())
        return nullptr;

    size_t init = 0;
    return deserialize_tree_helper(data, init);
}
