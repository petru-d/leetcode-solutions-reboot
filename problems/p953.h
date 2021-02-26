#pragma once
#include <array>
#include <string>
#include <vector>

namespace p953
{
    class Solution
    {
      public:
        bool isAlienSorted(std::vector<std::string>& words, std::string order)
        {
            std::array<size_t, 26> pos = {};
            for (size_t i = 0; i < order.size(); ++i)
                pos[order[i] - 'a'] = i;

            auto less_letter = [&pos](char l, char r) { return pos[l - 'a'] < pos[r - 'a']; };

            auto less_eq_word = [&less_letter](const std::string& l, const std::string& r) {
                auto sz = std::min(l.size(), r.size());
                for (size_t i = 0; i < sz; ++i)
                {
                    if (l[i] == r[i])
                        continue;

                    return less_letter(l[i], r[i]);
                }

                return l.size() <= r.size();
            };

            for (size_t i = 0; i < words.size() - 1; ++i)
            {
                if (!less_eq_word(words[i], words[i + 1]))
                    return false;
            }
            return true;
        }
    };
}
