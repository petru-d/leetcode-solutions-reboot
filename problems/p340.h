#pragma once
#include <string>
#include<unordered_map>

namespace p340
{
    class Solution
    {
      public:
        int lengthOfLongestSubstringKDistinct(std::string s, int k)
        {
            if (k == 0)
                return 0;

            auto S = s.length();
            if (S <= 1)
                return int(S);

            size_t count = 0;
            std::unordered_map<char, size_t> h;
            auto add = [&h, &count](char c) {
                auto [pos, i] = h.insert({c, 1});
                if (!i)
                    ++pos->second;
                else
                    ++count;
            };

            auto extract = [&h, &count](char c) {
                auto pos = h.find(c);
                if (pos->second == 1)
                {
                    h.erase(pos);
                    --count;
                }
                else
                {
                    --pos->second;
                }
            };

            size_t l = 0;
            size_t r = 1;
            int max = 1;
            add(s[l]);
            while (r < S)
            {
                add(s[r]);
                ++r;
                while (count > k)
                {
                    extract(s[l]);
                    ++l;
                }
                max = std::max(max, int(r - l));
            }

            return max;
        }
    };
}
