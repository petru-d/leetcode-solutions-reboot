#pragma once
#include <algorithm>
#include <vector>

namespace p905
{
    class Solution
    {
      public:
        std::vector<int> sortArrayByParity(std::vector<int>& A)
        {
            std::partition(A.begin(), A.end(), [](int i) { return i % 2 == 0; });
            return A;
        }
    };
}
