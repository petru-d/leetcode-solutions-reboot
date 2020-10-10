#pragma once
#include "util_binary_tree.h"
#include <cassert>
#include <string>

namespace p449
{
    class Codec
    {
      public:
        std::string serialize(TreeNode* root)
        {
            std::string data;
            serialize_helper(root, data);
            return data;
        }

        void serialize_helper(TreeNode* root, std::string& data)
        {
            if (root == nullptr)
                return;

            data.append(std::to_string(root->val));
            data.append(1, ' ');

            serialize_helper(root->left, data);
            serialize_helper(root->right, data);
        }

        TreeNode* deserialize(std::string data)
        {
            if (data.empty())
                return nullptr;

            std::istringstream is(data);

            struct Range
            {
                int Low = std::numeric_limits<int>::min();
                int High = std::numeric_limits<int>::max();
                bool contains(int n)
                {
                    return Low <= n && n <= High;
                }
            };

            struct NodeInfo
            {
                TreeNode* Node = nullptr;
                Range AllowedLeft;
                Range AllowedRight;

                std::optional<NodeInfo> accept(int n)
                {
                    if (AllowedLeft.contains(n))
                    {
                        auto* node = new TreeNode(n);
                        Node->left = node;
                        Range newAllowedLeft = {AllowedLeft.Low, n};
                        Range newAllowedRight = {n, AllowedLeft.High};

                        return NodeInfo{node, newAllowedLeft, newAllowedRight};
                    }
                    if (AllowedRight.contains(n))
                    {
                        auto* node = new TreeNode(n);
                        Node->right = node;
                        Range newAllowedLeft = {AllowedRight.Low, n};
                        Range newAllowedRight = {n, AllowedRight.High};

                        return NodeInfo{node, newAllowedLeft, newAllowedRight};
                    }
                    return {};
                }
            };

            std::vector<NodeInfo> stack;
            int n = 0;
            is >> n;
            auto* root = new TreeNode(n);
            stack.push_back(NodeInfo{root, {std::numeric_limits<int>::min(), n}, {n, std::numeric_limits<int>::max()}});

            while (is >> n)
            {
                std::optional<NodeInfo> accepted;
                while (!(accepted = stack.back().accept(n)))
                    stack.pop_back();
                stack.push_back(accepted.value());
            }

            return root;
        }
    };
}