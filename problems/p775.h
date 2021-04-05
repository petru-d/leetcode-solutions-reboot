#pragma once
#include <algorithm>
#include <vector>

namespace p775
{
    class Solution
    {
      public:
        bool isIdealPermutation(std::vector<int>& A)
        {
            auto AA = A.size();

            for (size_t i = 0; i < AA; ++i)
                if (std::abs(int(i) - A[i]) > 1)
                    return false;

            return true;
        }
    };
}
