#pragma once
#include <ctime>
#include <numeric>
#include <vector>

namespace p528
{
    class Solution
    {
      public:
        Solution(std::vector<int>& w)
        {
            _probs_sums.reserve(w.size());

            auto sum = std::accumulate(w.begin(), w.end(), 0);

            _probs_sums.push_back(double(w[0]) / sum);

            for (size_t i = 1; i < w.size(); ++i)
                _probs_sums.push_back(_probs_sums[i - 1] + (double(w[i])) / sum);

            std::srand(static_cast<unsigned int>(std::time(nullptr)));
        }

        int pickIndex()
        {
            double n = (double(rand())) / RAND_MAX;

            auto pos = std::lower_bound(_probs_sums.begin(), _probs_sums.end(), n);

            return int(std::distance(_probs_sums.begin(), pos));
        }

        std::vector<double> _probs_sums;
    };
}