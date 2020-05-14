#pragma once
#include <vector>

namespace p540
{
    class Solution
    {
      public:
        int singleNonDuplicate(std::vector<int>& nums)
        {
            size_t N = nums.size();
            if (N == 0)
                return -1;
            return search(nums, 0, N - 1);
        }

      private:
        int search(const std::vector<int>& nums, size_t l, size_t r)
        {
            if (l + 1 >= r)
                return unique(nums, l) ? nums[l] : nums[r];

            size_t pivot = (l + r) / 2;

            if ((nums[pivot] == nums[pivot + 1] && pivot % 2 == 0) || (nums[pivot - 1] == nums[pivot] && pivot % 2 == 1))
                return search(nums, pivot, r);

            if ((nums[pivot] == nums[pivot + 1] && pivot % 2 == 1) || (nums[pivot - 1] == nums[pivot] && pivot % 2 == 0))
                return search(nums, l, pivot);

            return nums[pivot];
        }

        bool unique(const std::vector<int>& nums, size_t p)
        {
            bool l_ok = p == 0 || nums[p] != nums[p - 1];
            bool r_ok = p == nums.size() - 1 || nums[p] != nums[p + 1];

            return l_ok && r_ok;
        }
    };
}