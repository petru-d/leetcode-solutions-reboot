#pragma once
#include <string>
#include <array>
#include <algorithm>

namespace p266
{
    class Solution
    {
      public:
        bool canPermutePalindrome(std::string s)
        {
            std::array<size_t, 256> h = {};
            for (const auto c : s)
                ++h[c];

            auto count_odd = std::count_if(h.begin(), h.end(), [](size_t i) { return i % 2 == 1; });

            return count_odd <= 1;
        }
    };
}
