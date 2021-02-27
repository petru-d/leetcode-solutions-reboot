#pragma once
#include <string>
#include <vector>

namespace p821
{
    class Solution
    {
      public:
        std::vector<int> shortestToChar(std::string s, char c)
        {
            auto S = s.size();
            std::vector<int> result(S, 0);
            auto fill_start = [&](size_t until) {
                for (size_t i = 0; i < until; ++i)
                    result[i] = until - i;
            };
            auto fill_end = [&](size_t from) {
                for (size_t i = from; i < S; ++i)
                    result[i] = i - from;
            };
            auto fill_mid = [&](size_t from, size_t until) {
                auto [mid, q] = std::div(until + from, 2);
                for (size_t i = from; i <= mid; ++i)
                    result[i] = i - from;
                for (size_t i = mid + q; i < until; ++i)
                    result[i] = until - i;
            };

            size_t first = -1;
            for (first = 0; first < S; ++first)
            {
                if (s[first] == c)
                {
                    fill_start(first);
                    break;
                }
            }

            size_t prev = first;
            for (size_t i = first + 1; i < S; ++i)
            {
                if (s[i] == c)
                {
                    fill_mid(prev, i);
                    prev = i;
                }
            }
            fill_end(prev);

            return result;
        }
    };
}
