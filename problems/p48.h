#pragma once
#include <vector>

namespace p48
{
    class Solution
    {
      public:
        void rotate(std::vector<std::vector<int>>& matrix)
        {
            auto N = matrix.size();

            auto H = N % 2 == 1 ? (N - 1) / 2 : N / 2;

            for (size_t i = 0; i < H + N % 2; ++i)
                for (size_t j = 0; j < H; ++j)
                {
                    // [i, j]           [j, N - 1 - i]
                    //
                    // [N - 1 - j, i]   [N - 1 - i, N - 1 - j]
                    std::swap(matrix[i][j], matrix[j][N - 1 - i]);
                    std::swap(matrix[N - 1 - j][i], matrix[N - 1 - i][N - 1 - j]);
                    std::swap(matrix[i][j], matrix[N - 1 - i][N - 1 - j]);
                }
        }
    };
}
