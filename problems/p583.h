#pragma once
#include <numeric>
#include <string>
#include <vector>

namespace p583
{
    class Solution
    {
      public:
        int minDistance(std::string word1, std::string word2)
        {
            auto W1 = word1.size();
            auto W2 = word2.size();

            // Initialize to distance from w1 to nothing. Starts with dist from nothing to nothing.
            std::vector<int> edit_dist_del(W1 + 1, 0);
            std::iota(edit_dist_del.begin(), edit_dist_del.end(), 0);

            std::vector<int> new_edit_dist_del(W1 + 1, 0);
            for (size_t i = 1; i <= W2; ++i)
            {
                new_edit_dist_del[0] = i;
                for (size_t j = 1; j <= W1; ++j)
                {
                    int best = std::min(1 + edit_dist_del[j], 1 + new_edit_dist_del[j - 1]);
                    if (word1[j - 1] == word2[i - 1])
                        best = std::min(best, edit_dist_del[j - 1]);
                    new_edit_dist_del[j] = best;
                }

                std::swap(edit_dist_del, new_edit_dist_del);
            }

            return edit_dist_del.back();
        }
    };
}
