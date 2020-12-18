#pragma once
#include <vector>

namespace p941
{
    class Solution
    {
      public:
        bool validMountainArray(std::vector<int>& arr)
        {
            auto A = arr.size();
            if (A < 3)
                return false;
            if (arr[1] <= arr[0])
                return false;

            bool ascending = true;
            for (size_t i = 2; i < A; ++i)
            {
                if (arr[i] == arr[i - 1])
                    return false;

                if (arr[i] < arr[i - 1])
                    ascending = false;

                if (arr[i] > arr[i - 1] && !ascending)
                    return false;
            }

            return !ascending;
        }
    };
}
