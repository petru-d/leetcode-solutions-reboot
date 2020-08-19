#pragma once
#include <vector>

namespace p1089
{
    class Solution
    {
      public:
        void duplicateZeros(std::vector<int>& arr)
        {
            size_t A = arr.size();
            if (A <= 1)
                return;

            size_t curr_ok = 0;
            for (size_t i = 0; i < A; ++i)
            {
                int v = arr[i] % 10;
                arr[curr_ok++] += 10 * v;
                if (curr_ok == A)
                    break;

                if (v == 0)
                {
                    arr[curr_ok++] += 10 * v;
                    if (curr_ok == A)
                        break;
                }
            }
            for (size_t i = 0; i < A; ++i)
                arr[i] /= 10;
        }
    };
}
