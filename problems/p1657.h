#pragma once
#include <array>
#include <string>
#include <algorithm>

namespace p1657
{
    class Solution
    {
      public:
        bool closeStrings(std::string word1, std::string word2)
        {
            if (word1.size() != word2.size())
                return false;

            std::array<size_t, 26> w1sig = {};
            std::array<size_t, 26> w2sig = {};

            for (const auto w : word1)
                ++w1sig[w - 'a'];
            for (const auto w : word2)
                ++w2sig[w - 'a'];

            for (size_t i = 0; i < 26; ++i)
            {
                bool empty1 = w1sig[i] == 0;
                bool empty2 = w2sig[i] == 0;

                if (empty1 ^ empty2)
                    return false;
            }

            std::sort(w1sig.begin(), w1sig.end());
            std::sort(w2sig.begin(), w2sig.end());

            return w1sig == w2sig;
        }
    };
}
