#pragma once
#include <vector>

namespace p1343
{
    class Solution
    {
      public:
        int numOfSubarrays(std::vector<int>& arr, int k, int threshold)
        {
            if (k > arr.size())
                return 0;

            int res = 0;

            // Make the first average for the first window
            double avg = 0;
            for (size_t i = 0; i < k; ++i)
                avg += double(arr[i]) / k;
            if (avg >= threshold)
                ++res;

            // remove the left most, add current
            for (size_t i = k; i < arr.size(); ++i)
            {
                avg -= double(arr[i - k]) / k;
                avg += double(arr[i]) / k;
                if (avg >= threshold)
                    ++res;
            }

            return res;
        }
    };
}