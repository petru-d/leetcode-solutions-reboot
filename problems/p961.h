#pragma once
#include <cassert>
#include <vector>

namespace p961
{
    class Solution
    {
      public:
        int repeatedNTimes(std::vector<int>& A)
        {
            auto AA = A.size();
            if (AA == 4)
            {
                std::sort(A.begin(), A.end());
                for (size_t i = 1; i < AA; ++i)
                    if (A[i] == A[i - 1])
                        return A[i];
            }

            for (size_t i = 2; i < AA; ++i)
            {
                if (A[i] == A[i - 1] || A[i] == A[i - 2])
                    return A[i];
            }

            assert(false);
            return -1;
        }
    };
}
