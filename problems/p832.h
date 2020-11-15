#pragma once
#include <vector>

namespace p832
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A)
        {
            size_t N = A.size();

            for (size_t i = 0; i < N; ++i)
                for (size_t j = 0; j < N / 2; ++j)
                    std::swap(A[i][j], A[i][N - j - 1]);

            for (size_t i = 0; i < N; ++i)
                for (size_t j = 0; j < N; ++j)
                    A[i][j] = !A[i][j];

            return A;
        }
    };
}
