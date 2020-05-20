#pragma once
#include "util_binary_tree.h"
#include <vector>

namespace p108
{
    class Solution
    {
      public:
        TreeNode* sortedArrayToBST(std::vector<int>& nums)
        {
            size_t N = nums.size();
            return rec(nums, 0, N);
        }

      private:
        TreeNode* rec(const std::vector<int>& nums, size_t left, size_t right)
        {
            if (left == right)
            {
                return nullptr;
            }
            if (left + 1 == right)
            {
                return new TreeNode(nums[left]);
            }

            size_t mid = (left + right) / 2;

            return new TreeNode{nums[mid], rec(nums, left, mid), rec(nums, mid + 1, right)};
        }
    };
}