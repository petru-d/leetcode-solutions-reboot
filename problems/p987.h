#pragma once
#include "util_binary_tree.h"

#include <algorithm>
#include <map>
#include <vector>
namespace p987
{
    class Solution
    {
      public:
        // maps a number to a vector which contains all nodes with that number as an X coordiante
        // a node is stored as its Y coordinate and it's value
        using X_to_AllYVal = std::map<int, std::vector<std::pair<int, int>>>;
        std::vector<std::vector<int>> verticalTraversal(TreeNode* root)
        {
            // X to {Node, Y}
            X_to_AllYVal coords;
            std::pair<int, int> rootCoords = {0, 0};
            make_coords(root, rootCoords, coords);

            std::vector<std::vector<int>> result;
            for (auto& [x, allYval] : coords)
            {
                std::sort(allYval.begin(), allYval.end(), [](const auto& lYVal, const auto& rYVal) {
                    if (lYVal.first != rYVal.first)
                        return lYVal.first > rYVal.first;
                    return lYVal.second <= rYVal.second;
                });

                std::vector<int> r;
                r.reserve(allYval.size());
                std::transform(allYval.begin(), allYval.end(), std::back_inserter(r),
                               [](const std::pair<int, int> yVal) { return yVal.second; });
                result.push_back(std::move(r));
            }

            return result;
        }

      private:
        void make_coords(TreeNode* root, std::pair<int, int> rootCoords, X_to_AllYVal& coords)
        {
            if (!root)
                return;

            int X = rootCoords.first;
            int Y = rootCoords.second;

            coords[X].emplace_back(Y, root->val);

            make_coords(root->left, {rootCoords.first - 1, rootCoords.second - 1}, coords);
            make_coords(root->right, {rootCoords.first + 1, rootCoords.second - 1}, coords);
        }
    };
}
