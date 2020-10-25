#pragma once
#include <vector>

namespace p948
{
    class Solution
    {
      public:
        int bagOfTokensScore(std::vector<int>& tokens, int P)
        {
            size_t T = tokens.size();
            if (T == 0)
                return 0;

            std::sort(tokens.begin(), tokens.end());
            size_t left = 0;
            size_t right = T - 1;

            int score = 0;

            while (left <= right)
            {
                if (P >= tokens[left])
                {
                    ++score;
                    P -= tokens[left];
                    ++left;
                    continue;
                }
                if (score > 0 && (left + 1 < right && P + tokens[right] >= tokens[left]))
                {
                    --score;
                    P += tokens[right];
                    --right;
                    continue;
                }
                break;
            }

            return score;
        }
    };
}
