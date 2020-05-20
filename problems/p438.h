#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace p438
{
    class Solution
    {
      public:
        std::vector<int> findAnagrams(std::string s, std::string p)
        {
            size_t S = s.size();
            size_t P = p.size();

            if (P > S)
                return {};

            std::array<size_t, 26> p_sig = {};
            for (auto pc : p)
            {
                ++p_sig[pc - 'a'];
            }

            std::array<size_t, 26> curr_sig = {};
            for (size_t i = 0; i < P; ++i)
            {
                ++curr_sig[s[i] - 'a'];
            }

            size_t match_count = 0;
            for (size_t i = 0; i < 26; ++i)
                match_count += (p_sig[i] == curr_sig[i]);

            std::vector<int> result;
            if (match_count == 26)
                result.push_back(0);

            for (size_t i = 1; i < S - P + 1; ++i)
            {
                char exiting = s[i - 1];
                char entering = s[i - 1 + P];

                if (exiting != entering)
                {
                    bool pre_match_exiting = (p_sig[exiting - 'a'] == curr_sig[exiting - 'a']);
                    bool pre_match_entering = (p_sig[entering - 'a'] == curr_sig[entering - 'a']);

                    --curr_sig[exiting - 'a'];
                    ++curr_sig[entering - 'a'];

                    bool post_match_exiting = (p_sig[exiting - 'a'] == curr_sig[exiting - 'a']);
                    bool post_match_entering = (p_sig[entering - 'a'] == curr_sig[entering - 'a']);

                    match_count += pre_match_exiting ? -1 : post_match_exiting;
                    match_count += pre_match_entering ? -1 : post_match_entering;
                }

                if (match_count == 26)
                    result.push_back(int(i));
            }

            return result;
        }
    };
}