#pragma once
#include <vector>

namespace p896
{
    class Solution
    {
      public:
        bool isMonotonic(std::vector<int>& A)
        {
            bool maybe_increasing = true;
            bool maybe_decreasing = true;

            size_t AS = A.size();
            for (size_t i = 1; i < AS; ++i)
            {
                if (A[i - 1] < A[i])
                {
                    maybe_decreasing = false;
                    if (!maybe_increasing)
                        return false;
                }
                if (A[i - 1] > A[i])
                {
                    maybe_increasing = false;
                    if (!maybe_decreasing)
                        return false;
                }
            }

            return true;
        }
    };
}