#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

namespace p969
{
    class Solution
    {
      public:
        std::vector<int> pancakeSort(std::vector<int>& A)
        {
            size_t N = A.size();

            std::vector<int> result;

            for (size_t i = N; i > 0; --i)
            {
                // already in the correct position
                if (A[i - 1] == i)
                    continue;

                size_t posi = size_t(-1);
                for (size_t j = 0; j < i - 1; ++j)
                    if (A[j] == i)
                    {
                        posi = j;
                        break;
                    }
                assert(posi != size_t(-1));

                // bring to the front
                if (posi != 0)
                {
                    flip(A, posi);
                    result.push_back(static_cast<int>(posi + 1));
                }
                flip(A, i - 1);
                result.push_back(static_cast<int>(i));
            }

            return result;
        }

      private:
        void flip(std::vector<int>& A, size_t k)
        {
            std::reverse(A.begin(), A.begin() + k + 1);
        }
    };
}
