#pragma once
#include <vector>
#include <string>

namespace p243
{
    class Solution
    {
      public:
        int shortestDistance(std::vector<std::string>& words, std::string word1, std::string word2)
        {
            struct WordOccurence
            {
                size_t Pos;
                bool W1;
            };

            std::vector<WordOccurence> occurences;
            for (size_t w = 0; w < words.size(); ++w)
            {
                if (words[w] == word1)
                    occurences.push_back({w, true});
                else if (words[w] == word2)
                    occurences.push_back({w, false});
            }

            int minDist = std::numeric_limits<int>::max();

            for (size_t o = 1; o < occurences.size(); ++o)
            {
                if (occurences[o].W1 ^ occurences[o - 1].W1)
                    minDist = std::min(minDist, int(occurences[o].Pos - occurences[o - 1].Pos));
            }

            return minDist;
        }
    };
}
