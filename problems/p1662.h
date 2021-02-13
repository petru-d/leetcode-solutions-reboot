#pragma once
#include <vector>
#include <string>

namespace p1662
{
    class Solution
    {
      public:
        bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2)
        {
            std::pair<size_t, size_t> p1 = {0, 0};
            std::pair<size_t, size_t> p2 = {0, 0};

            auto at_end = [](const std::vector<std::string>& w, std::pair<size_t, size_t> p) {
                return p.first == size_t(-1) || p.second == size_t(-1);
            };

            auto advance = [&](const std::vector<std::string>& w, std::pair<size_t, size_t>& p) {
                if (at_end(w, p))
                    return;

                if (p.second == w[p.first].size() - 1)
                {
                    ++p.first;
                    p.second = 0;
                    if (p.first == w.size())
                        p = {-1, -1};
                }
                else
                {
                    ++p.second;
                    if (p.second == w[p.first].size())
                        p = {-1, -1};
                }
            };

            while (!at_end(word1, p1) && !at_end(word2, p2))
            {
                if (word1[p1.first][p1.second] != word2[p2.first][p2.second])
                    return false;
                advance(word1, p1);
                advance(word2, p2);
            }

            return at_end(word1, p1) && at_end(word2, p2);
        }
    };
}
