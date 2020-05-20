#pragma once
#include "util_binary_tree.h"
#include "util_linked_list.h"

#include <vector>

namespace p109
{
    class Solution
    {
      public:
        TreeNode* sortedListToBST(ListNode* head)
        {
            std::vector<int> nums;
            while (head != nullptr)
            {
                nums.push_back(head->val);
                head = head->next;
            }

            return sortedArrayToBST(nums);
        }

      private:
        TreeNode* sortedArrayToBST(std::vector<int>& nums)
        {
            size_t N = nums.size();
            return rec(nums, 0, N);
        }

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

            return new TreeNode(nums[mid], rec(nums, left, mid), rec(nums, mid + 1, right));
        }
    };
}