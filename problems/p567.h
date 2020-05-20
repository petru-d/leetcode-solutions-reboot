#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace p567
{
    class Solution
    {
      public:
        bool checkInclusion(std::string s1, std::string s2)
        {
            size_t S1 = s1.size();
            size_t S2 = s2.size();

            if (S1 > S2)
                return false;

            std::array<size_t, 26> s1_sig = {};
            for (auto s : s1)
            {
                ++s1_sig[s - 'a'];
            }

            std::array<size_t, 26> curr_sig = {};
            for (size_t i = 0; i < S1; ++i)
            {
                ++curr_sig[s2[i] - 'a'];
            }

            size_t match_count = 0;
            for (size_t i = 0; i < 26; ++i)
                match_count += (s1_sig[i] == curr_sig[i]);

            if (match_count == 26)
                return true;

            for (size_t i = 1; i < S2 - S1 + 1; ++i)
            {
                char exiting = s2[i - 1];
                char entering = s2[i - 1 + S1];

                if (exiting != entering)
                {
                    bool pre_match_exiting = (s1_sig[exiting - 'a'] == curr_sig[exiting - 'a']);
                    bool pre_match_entering = (s1_sig[entering - 'a'] == curr_sig[entering - 'a']);

                    --curr_sig[exiting - 'a'];
                    ++curr_sig[entering - 'a'];

                    bool post_match_exiting = (s1_sig[exiting - 'a'] == curr_sig[exiting - 'a']);
                    bool post_match_entering = (s1_sig[entering - 'a'] == curr_sig[entering - 'a']);

                    match_count += pre_match_exiting ? -1 : post_match_exiting;
                    match_count += pre_match_entering ? -1 : post_match_entering;
                }

                if (match_count == 26)
                    return true;
            }

            return false;
        }
    };
}