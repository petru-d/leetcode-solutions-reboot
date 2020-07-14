#pragma once

#include <numeric>
#include <vector>

namespace p688
{
    class Solution
    {
      public:
        double knightProbability(int N, int K, int r, int c)
        {
            size_t n = size_t(N);

            std::vector<std::vector<double>> probs(size_t(N), std::vector<double>(size_t(N), 0));
            probs[r][c] = 1;

            for (int k = 1; k <= K; ++k)
            {
                auto new_probs(probs);
                for (size_t i = 0; i < n; ++i)
                    for (size_t j = 0; j < n; ++j)
                    {
                        new_probs[i][j] =
                            ((i >= 1 && j >= 2 ? probs[i - 1][j - 2] : 0) + (i >= 2 && j >= 1 ? probs[i - 2][j - 1] : 0) +
                             (i >= 2 && j < n - 1 ? probs[i - 2][j + 1] : 0) + (i >= 1 && j < n - 2 ? probs[i - 1][j + 2] : 0) +
                             (i < n - 1 && j >= 2 ? probs[i + 1][j - 2] : 0) + (i < n - 2 && j >= 1 ? probs[i + 2][j - 1] : 0) +
                             (i < n - 2 && j < n - 1 ? probs[i + 2][j + 1] : 0) +
                             (i < n - 1 && j < n - 2 ? probs[i + 1][j + 2] : 0)) /
                            8.;
                    }

                std::swap(probs, new_probs);
            }

            double res = 0;
            for (const auto& p : probs)
                res += std::accumulate(p.begin(), p.end(), double(0));

            return res;
        }
    };
}
