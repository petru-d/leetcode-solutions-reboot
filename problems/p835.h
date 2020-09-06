#pragma once
#include <algorithm>
#include <vector>

namespace p835
{
    class Solution
    {
      public:
        int largestOverlap(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B)
        {
            using matrix = std::vector<std::vector<int>>;

            size_t N = A.size();

            size_t onesA = 0;
            for (size_t i = 0; i < N; ++i)
                for (size_t j = 0; j < N; ++j)
                    onesA += A[i][j];

            size_t onesB = 0;
            for (size_t i = 0; i < N; ++i)
                for (size_t j = 0; j < N; ++j)
                    onesB += B[i][j];

            size_t best_possible = std::min(onesA, onesB);
            if (best_possible <= 1 || onesA == N * N || onesB == N * N)
                return static_cast<int>(best_possible);

            auto overlap = [N](const matrix& A, const matrix& B, size_t x, size_t y) {
                size_t res = 0;
                for (size_t i = 0; i < N - x; ++i)
                    for (size_t j = 0; j < N - y; ++j)
                        res += static_cast<size_t>(A[i][j]) * B[x + i][y + j];

                return res;
            };

            size_t res = 1;
            for (size_t x = 0; x < N; ++x)
                for (size_t y = 0; y < N; ++y)
                    res = std::max({res, overlap(A, B, x, y), overlap(B, A, x, y)});

            return static_cast<int>(res);
        }
    };
}
