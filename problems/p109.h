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
    class Solution2
    {
      public:
        TreeNode* sortedListToBST(ListNode* head)
        {

            std::vector<int> data;
            while (head)
            {
                data.push_back(head->val);
                head = head->next;
            }

            return make(data, 0, data.size());
        }

        TreeNode* make(const std::vector<int>& data, size_t start, size_t end)
        {
            if (start >= end)
                return nullptr;

            auto mid = (start + end) / 2;

            auto* root = new TreeNode(data[mid]);

            root->left = make(data, start, mid);
            root->right = make(data, mid + 1, end);

            return root;
        }
    };
}