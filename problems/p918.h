#pragma once
#include <algorithm>
#include <vector>

namespace p918
{
    class Solution
    {
      public:
        int maxSubarraySumCircular(std::vector<int>& A)
        {
            size_t N = A.size();
            int best_sum = A[0];
            int worst_sum = A[0];
            int curr_best_sum = A[0];
            int curr_worst_sum = A[0];
            int total = A[0];
            for (size_t i = 1; i < N; ++i)
            {
                total += A[i];

                curr_best_sum = std::max(A[i], curr_best_sum + A[i]);
                best_sum = std::max(best_sum, curr_best_sum);

                curr_worst_sum = std::min(A[i], curr_worst_sum + A[i]);
                worst_sum = std::min(worst_sum, curr_worst_sum);
            }

            if (total == worst_sum)
            {
                return best_sum;
            }
            return std::max(best_sum, total - worst_sum);
        }
    };
}