#pragma once
#include "util_binary_tree.h"
#include <unordered_map>
#include <vector>
namespace p971
{
    // keep map to know where to find nodes - kinda ugly
    class Solution
    {
      public:
        std::vector<int> flipMatchVoyage(TreeNode* root, std::vector<int>& voyage)
        {
            if (!root)
                return {-1};

            std::unordered_map<int, size_t> posInVoyage;
            auto V = voyage.size();
            for (size_t i = 0; i < V; ++i)
                posInVoyage[voyage[i]] = i;

            std::vector<int> flip;
            auto res = go(root, 0, voyage.size() - 1, posInVoyage, flip);
            return res ? flip : std::vector<int>{-1};
        }

        bool go(TreeNode* root, size_t left, size_t right, std::unordered_map<int, size_t>& posInVoyage, std::vector<int>& flip)
        {
            auto rootPos = posInVoyage[root->val];
            if (rootPos != left)
                return false;

            if (!root->left && !root->right)
                return true;

            if (!root->left || !root->right)
            {
                auto* nonNullChild = root->left ? root->left : root->right;

                auto childPos = posInVoyage[nonNullChild->val];

                if (childPos != left + 1 || childPos > right)
                    return false;
                return go(nonNullChild, left + 1, right, posInVoyage, flip);
            }

            auto leftChildPos = posInVoyage[root->left->val];
            auto rightChildPos = posInVoyage[root->right->val];

            if ((leftChildPos != rootPos + 1 && rightChildPos != rootPos + 1) || leftChildPos > right || rightChildPos > right)
                return false;

            bool flipped = false;
            if (leftChildPos != rootPos + 1)
            {
                flipped = true;
                flip.push_back(root->val);
            }

            auto leftOk = go(root->left, leftChildPos, flipped ? right : rightChildPos - 1, posInVoyage, flip);
            if (!leftOk)
                return false;

            return go(root->right, rightChildPos, flipped ? leftChildPos - 1 : right, posInVoyage, flip);
        }
    };

    // better - just advance one step per call, taking care to process the correct child
    class Solution2
    {
      public:
        std::vector<int> flipMatchVoyage(TreeNode* root, std::vector<int>& voyage)
        {
            if (!root)
                return {};

            std::vector<int> flipped;
            size_t currPos = 0;
            if (!go(root, voyage, currPos, flipped))
                return {-1};
            return flipped;
        }

        bool go(TreeNode* root, const std::vector<int>& voyage, size_t& currPos, std::vector<int>& flipped)
        {
            if (!root)
                return true;

            if (voyage[currPos++] != root->val)
                return false;

            bool swapped = false;
            if (root->left && root->left->val != voyage[currPos])
            {
                flipped.push_back(root->val);
                swapped = true;
            }

            bool leftOk = go(swapped ? root->right : root->left, voyage, currPos, flipped);
            if (!leftOk)
                return false;

            return go(swapped ? root->left : root->right, voyage, currPos, flipped);
        }
    };
}
