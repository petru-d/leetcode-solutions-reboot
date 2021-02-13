#pragma once
#include <vector>

namespace p910
{
    class Solution
    {
      public:
        int smallestRangeII(std::vector<int>& A, int K)
        {
            auto AA = A.size();
            if (AA == 1)
                return 0;
            K = std::abs(K);

            // if A[i] < A[i + 1], it is never useful to consider range {A[i] - K, A[i + 1] + K} -
            // we're just increasing the interval
            // this means that there is exactly one "turning point", up
            // to which all elements point up and after that all point down.

            std::sort(std::begin(A), std::end(A));

            int result = A.back() - A.front();

            // algorithm: what do we get if the first down turn is at poition i + 1 ?
            for (size_t i = 0; i < AA - 1; ++i)
            {
                int curr = A[i];
                int next = A[i + 1];

                // points up, adjusts max
                int high = std::max(curr + K, A[AA - 1] - K);

                // points down, adjusts min
                int low = std::min(next - K, A[0] + K);

                result = std::min(result, high - low);
            }

            return result;
        }
    };
}
