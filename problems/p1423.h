#pragma once
#include <numeric>
#include <vector>

namespace p1423
{
    class Solution2
    {
      public:
        int maxScore(std::vector<int>& cardPoints, int k)
        {
            auto C = cardPoints.size();

            size_t window_size = k >= C ? 0 : C - size_t(k);

            int total_sum = 0;
            int curr_window_amount = 0;
            for (size_t w = 0; w < window_size; ++w)
            {
                curr_window_amount += cardPoints[w];
                total_sum += cardPoints[w];
            }

            int min_window_amount = curr_window_amount;
            for (size_t i = window_size; i < C; ++i)
            {
                total_sum += cardPoints[i];
                curr_window_amount += cardPoints[i] - cardPoints[i - window_size];
                min_window_amount = std::min(min_window_amount, curr_window_amount);
            }

            return total_sum - min_window_amount;
        }
    };

    class Solution
    {
      public:
        int maxScore(std::vector<int>& cardPoints, int k)
        {
            auto C = cardPoints.size();
            auto K = size_t(k);
            if (K >= C)
                return std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
            if (K == 0)
                return 0;

            int curr_score = 0;
            for (size_t i = 0; i < K; ++i)
                curr_score += cardPoints[i];

            int best_score = curr_score;
            for (size_t i = 0; i < K; ++i)
            {
                curr_score += cardPoints[C - 1 - i] - cardPoints[K - 1 - i];
                best_score = std::max(best_score, curr_score);
            }

            return best_score;
        }
    };
}
