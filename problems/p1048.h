#pragma once
#include <array>
#include <string>
#include <vector>

namespace p1048
{
    class Solution
    {
      public:
        int longestStrChain(std::vector<std::string>& words)
        {
            auto predecessor = [](const std::string& pred, const std::string& word) {
                auto P = pred.size();
                size_t diff_point = -1;
                for (size_t i = 0; i < P; ++i)
                {
                    if (pred[i] != word[i])
                    {
                        diff_point = i;
                        break;
                    }
                }

                if (diff_point == -1)
                {
                    return true;
                }

                // aaaabbbb
                // aaaaDbbbb

                for (size_t i = diff_point + 1; i < P + 1; ++i)
                    if (pred[i - 1] != word[i])
                    {
                        return false;
                    }
                return true;
            };

            // by_length[i] contains words with length i
            std::array<std::vector<std::string>, 17> by_length = {};
            for (auto& w : words)
            {
                auto sz = w.size();
                by_length[sz].push_back(std::move(w));
            }

            // for each word, the length of the longest chain ending at that word
            std::unordered_map<std::string, size_t> longest_chains;

            size_t absolute_longest = 1;

            for (size_t l = 1; l <= 16; ++l)
            {
                for (const auto& curr_word : by_length[l])
                {
                    size_t longest_curr = 1;
                    for (const auto& prev_word : by_length[l - 1])
                    {
                        if (predecessor(prev_word, curr_word))
                            longest_curr = std::max(longest_curr, 1 + longest_chains[prev_word]);
                    }
                    longest_chains[curr_word] = longest_curr;
                    absolute_longest = std::max(absolute_longest, longest_curr);
                }
            }

            return absolute_longest;
        }
    };
}
