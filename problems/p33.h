#pragma once
#include <cassert>
#include <vector>

namespace p33
{
    // Had this one in the old solution, but wanted to reimplement it recursivelly.
    class Solution
    {
      public:
        int search(std::vector<int>& nums, int target)
        {
            if (nums.empty())
                return -1;

            return bsearch_mixed(nums, target, 0, nums.size() - 1);
        }

        int bsearch_mixed(const std::vector<int>& nums, int target, size_t l, size_t r)
        {
            if (l + 1 >= r)
            {
                if (nums[l] == target)
                    return static_cast<int>(l);
                if (nums[r] == target)
                    return static_cast<int>(r);
                return -1;
            }

            // we are searching in a sub-array that contains two increasing sequences:
            // l0 < l1 < .. lk > r0 < r1 < .. < rq (also rq < l0)
            // or is completely sorted

            // when bisecting the array, at least one of the parts will be completely sorted
            size_t pivot = (l + r) / 2;
            if (nums[pivot] == target)
                return static_cast<int>(pivot);
            bool left_sorted = nums[l] <= nums[pivot];
            bool right_sorted = nums[pivot] <= nums[r];

            if (left_sorted)
            {
                // left part is sorted and our target is in there (if at all)
                if (nums[l] <= target && target <= nums[pivot])
                    return bsearch_mixed(nums, target, l, pivot);

                // left is sorted, but our target is not in there - search in the other side
                return bsearch_mixed(nums, target, pivot, r);
            }

            if (right_sorted)
            {
                // right part is sorted and our target is in there (if at all)
                if (nums[pivot] <= target && target <= nums[r])
                    return bsearch_mixed(nums, target, pivot, r);

                // right part is sorted, but our target is not in there - search in the other side
                return bsearch_mixed(nums, target, l, pivot);
            }

            assert(false);
            return -1;
        }
    };
}