#pragma once
#include <algorithm>
#include <vector>

namespace p1200
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr)
        {
            std::sort(arr.begin(), arr.end());

            std::vector<std::vector<int>> result;

            size_t A = arr.size();
            int min_diff = std::numeric_limits<int>::max();
            for (size_t i = 1; i < A; ++i)
            {
                if (min_diff < arr[i] - arr[i - 1])
                    continue;
                if (min_diff > arr[i] - arr[i - 1])
                {
                    min_diff = arr[i] - arr[i - 1];
                    result.clear();
                }
                result.emplace_back(std::vector<int>{arr[i - 1], arr[i]});
            }

            return result;
        }
    };
}
