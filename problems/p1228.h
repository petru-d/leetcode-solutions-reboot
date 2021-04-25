#pragma once
#include <numeric>
#include <vector>

namespace p1228
{
    // can also look at the first two gaps: if one is bigger in abs value than the other, the missing number is in the middle of
    // the big one if they are the same, look for the first gap that differs from them - our number is in the middle of it
    class Solution
    {
      public:
        int missingNumber(std::vector<int>& arr)
        {
            // arithmetic progression sum = n*a + k * n * (n - 1) / 2
            // - a is the first term
            // - k is the progression rate
            // - n is the number of terms to add

            // for us,
            // a is arr[0]
            // n is arr.size() + 1
            // get the deltas d1 = |a[0] - a[1]| and d2 = |a[1] - a[2]|
            // k = d1 <= d2 ? a[1] - a[0] : a[2] - a[1]

            int k = std::abs(arr[0] - arr[1]) <= std::abs(arr[1] - arr[2]) ? arr[1] - arr[0] : arr[2] - arr[1];

            int n = int(arr.size()) + 1;

            int a = arr[0];

            int total_sum = n * a + k * n * (n - 1) / 2;

            return total_sum - std::accumulate(arr.begin(), arr.end(), 0);
        }
    };
}
