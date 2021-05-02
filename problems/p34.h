#pragma once
#include <vector>

namespace p34
{
    class Solution
    {
      public:
        int search_first(const std::vector<int>& nums, int target, int left, int right)
        {
            if (1 + left >= right)
            {
                return target == nums[left] ? left : target == nums[right] ? right : -1;
            }

            int pivot = (left + right) / 2;

            if (nums[pivot] >= target)
                return search_first(nums, target, left, pivot);

            return search_first(nums, target, pivot, right);
        }

        int search_last(const std::vector<int>& nums, int target, int left, int right)
        {
            if (1 + left >= right)
            {
                return target == nums[right] ? right : target == nums[left] ? left : -1;
            }

            int pivot = (left + right) / 2;

            if (nums[pivot] <= target)
                return search_last(nums, target, pivot, right);

            return search_last(nums, target, left, pivot);
        }

        std::vector<int> searchRange(std::vector<int>& nums, int target)
        {
            if (nums.empty())
                return {-1, -1};

            auto low = search_first(nums, target, 0, int(nums.size()) - 1);
            if (-1 == low)
                return {-1, -1};

            return {low, search_last(nums, target, 0, int(nums.size()) - 1)};
        }
    };
    class Solution2
    {
      public:
        std::vector<int> searchRange(std::vector<int>& nums, int target)
        {
            auto [first, last] = std::equal_range(nums.begin(), nums.end(), target);

            if (first == last)
                return {-1, -1};

            return {int(std::distance(nums.begin(), first)), int(std::distance(nums.begin(), last) - 1)};
        }
    };
}
