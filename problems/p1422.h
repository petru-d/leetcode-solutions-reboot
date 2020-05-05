#pragma once

#include <algorithm>
#include <string>

namespace p1422
{
    class Solution
    {
      public:
        int maxScore(std::string s)
        {
            size_t ones = std::count(s.begin(), s.end(), '1');

            size_t current_score = ones + (s[0] == '1' ? -1 : 1);
            size_t best_score = current_score;

            size_t S = s.size();
            for (size_t i = 1; i < S - 1; ++i)
            {
                if (s[i] == '0')
                {
                    best_score = std::max(++current_score, best_score);
                }
                else
                    --current_score;
            }

            return static_cast<int>(best_score);
        }
    };
}