#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p318
{
    class Solution
    {
      public:
        int maxProduct(std::vector<std::string>& words)
        {
            auto W = words.size();

            std::vector<uint32_t> word_signs;
            word_signs.reserve(W);
            for (const auto& w : words)
            {
                uint32_t curr_sign = 0;
                for (const auto l : w)
                    curr_sign |= 1 << (l - 'a');

                word_signs.push_back(curr_sign);
            }

            size_t result = 0;
            for (size_t i = 0; i < W; ++i)
                for (size_t j = i + 1; j < W; ++j)
                {
                    if (word_signs[i] & word_signs[j])
                        continue;
                    result = std::max(result, words[i].size() * words[j].size());
                }

            return int(result);
        }
    };

    class Solution2
    {
      public:
        int maxProduct(std::vector<std::string>& words)
        {
            // bigger words have bigger indices
            std::sort(words.begin(), words.end(), [](const auto& l, const auto& r) { return l.size() < r.size(); });

            auto W = words.size();

            // e.g. by_missing_letter['c' - 'a'] = indices of words that don't have letter c
            std::array<std::set<size_t>, 26> by_missing_letter;

            // for each word, the letters that are present
            std::vector<std::array<uint8_t, 26>> word_signs;
            word_signs.reserve(W);

            for (size_t i = 0; i < W; ++i)
            {
                word_signs.push_back(std::array<uint8_t, 26>{});
                for (const auto l : words[i])
                    word_signs.back()[l - 'a'] = 1;

                for (size_t li = 0; li < 26; ++li)
                    if (word_signs.back()[li] == 0)
                        by_missing_letter[li].insert(i);
            }

            size_t result = 0;
            for (size_t i = 0; i < W; ++i)
            {
                // intersect all the sets that miss all the letters present in w
                std::set<size_t> intersection;
                size_t l = 0;
                for (; l < 26; ++l)
                    if (word_signs[i][l] == 1)
                    {
                        intersection = by_missing_letter[l];
                        break;
                    }
                for (++l; l < 26; ++l)
                {
                    std::set<size_t> new_intersection;
                    if (word_signs[i][l] == 1)
                    {
                        std::set_intersection(by_missing_letter[l].begin(), by_missing_letter[l].end(), intersection.begin(),
                                              intersection.end(), std::inserter(new_intersection, new_intersection.end()));
                        intersection = std::move(new_intersection);
                        if (intersection.empty())
                            break;
                    }
                }

                if (intersection.empty())
                    continue;

                result = std::max(result, words[i].size() * words[*intersection.rbegin()].size());
            }

            return result;
        }
    };
}
