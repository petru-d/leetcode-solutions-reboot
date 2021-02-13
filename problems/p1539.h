#pragma once
#include <vector>

namespace p1539
{
    class Solution
    {
      public:
        int findKthPositive(std::vector<int>& arr, int k)
        {
            if (k < arr[0])
                return k;

            if (k > arr.back() - arr.size())
                return k + arr.size();

            return search(arr, 0, arr.size(), k - arr[0] + 1);
        }

        int search(const std::vector<int>& arr, size_t lo, size_t hi, int k)
        {
            if (lo + 1 >= hi)
            {
                return arr[lo] + k;
            }

            size_t mid = (hi + lo) / 2;

            int missing_till_mid = arr[mid] - mid - 1;

            int missing_till_first = arr[lo] - lo - 1;

            if (k <= missing_till_mid - missing_till_first)
                return search(arr, lo, mid, k);

            return search(arr, mid, hi, k - missing_till_mid + missing_till_first);
        }
    };
}
