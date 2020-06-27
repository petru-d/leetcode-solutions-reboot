#pragma once

#include "util_binary_tree.h"

#include <cassert>
#include <charconv>
#include <string>

namespace p297
{
    class Codec
    {
      public:
        // Encodes a tree to a single string.
        std::string serialize(TreeNode* root)
        {
            std::string buffer;
            serialize_tree(root, buffer);
            return buffer;
        }

        // Decodes your encoded data to tree.
        TreeNode* deserialize(std::string data)
        {
            if (data.empty())
                return nullptr;

            size_t init = 0;
            return deserialize_tree(data, init);
        }

      private:
        void serialize_tree(const TreeNode* root, std::string& buffer)
        {
            if (nullptr == root)
                return;
            buffer.append(std::to_string(root->val));
            if (root->left == nullptr && root->right == nullptr)
                return;
            buffer += "(";

            if (root->left != nullptr)
                serialize_tree(root->left, buffer);

            buffer += ",";

            if (root->right != nullptr)
                serialize_tree(root->right, buffer);

            buffer += ")";
        }

        TreeNode* deserialize_tree(const std::string& data, size_t& pos)
        {
            auto get_num = [](const std::string& data, size_t& pos) {
                size_t end_pos = pos;
                while (end_pos < data.size() && (std::isdigit(data[end_pos]) || data[end_pos] == '-'))
                    ++end_pos;

                int num = 0;
                auto [p, ec] = std::from_chars(data.data() + pos, data.data() + end_pos, num);
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
                res->right = deserialize_tree(data, pos);
                assert(pos < data.size() && data[pos] == ')');
                ++pos;
                return res;
            }

            res->left = deserialize_tree(data, pos);
            assert(pos < data.size() && data[pos] == ',');

            ++pos;
            assert(pos < data.size());
            if (data[pos] == ')')
            {
                ++pos;
                return res;
            }
            res->right = deserialize_tree(data, pos);
            assert(pos < data.size() && data[pos] == ')');
            ++pos;
            return res;
        }
    };
}
