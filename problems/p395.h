#pragma once
#include <string>
#include <array>

namespace p395
{
    class Solution
    {
      public:
        int longestSubstring(std::string s, int k)
        {
            return longestSubstring(s, 0, s.size(), k);
        }

        int longestSubstring(const std::string& s, size_t l, size_t r, int k)
        {
            // std::cout << l << " " << r << endl;
            size_t S = s.size();
            if (l >= S)
                return 0;

            std::array<size_t, 26> cnt = {};
            for (size_t i = l; i < r; ++i)
                ++cnt[size_t(s[i]) - 'a'];

            // does character at pos appear >= k times?
            auto more_than_k = [&s, &cnt, k](size_t pos) { return cnt[size_t(s[pos]) - 'a'] != 0 && cnt[size_t(s[pos]) - 'a'] >= k; };

            auto any_less_k = std::any_of(cnt.begin(), cnt.end(), [k](size_t c) { return 0 < c && c < k; });
            if (!any_less_k)
                return int(r - l);

            int best = 0;

            size_t curr_l = l;
            size_t curr_r = l;
            while (curr_l < S)
            {
                while (curr_l < S && !more_than_k(curr_l))
                {
                    ++curr_l;
                    ++curr_r;
                }
                while (curr_r < S && more_than_k(curr_r))
                {
                    ++curr_r;
                }
                best = std::max(best, longestSubstring(s, curr_l, curr_r, k));
                curr_l = curr_r;
            }

            return best;
        }
    };
}
