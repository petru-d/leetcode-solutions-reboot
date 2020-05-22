#pragma once

#include <algorithm>
#include <array>
#include <string>

namespace p451
{
    class Solution
    {
      public:
        std::string frequencySort(std::string s)
        {
            struct char_freq
            {
                size_t freq = 0;
                char c = 0;
                bool operator<(const char_freq& other) const
                {
                    return freq < other.freq;
                }
            };

            constexpr char first_char = ' ';
            constexpr char last_char = 'z' + 1;
            std::array<char_freq, last_char - first_char> freqs = {};

            for (auto c : s)
            {
                ++freqs[c - size_t(first_char)].freq;
                freqs[c - size_t(first_char)].c = c;
            }

            std::sort(freqs.rbegin(), freqs.rend());

            size_t curr_index = 0;
            for (size_t f = 0; f < last_char - first_char; ++f)
            {
                if (freqs[f].freq == 0)
                    break;

                std::fill(s.begin() + curr_index, s.begin() + curr_index + freqs[f].freq, freqs[f].c);
                curr_index += freqs[f].freq;
            }

            return s;
        }
    };
}