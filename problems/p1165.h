#pragma once
#include <array>
#include <string>

namespace p1165
{
    class Solution
    {
      public:
        int calculateTime(std::string keyboard, std::string word)
        {
            std::array<int, 26> pos;
            for (size_t k = 0; k < 26; ++k)
                pos[keyboard[k] - 'a'] = int(k);

            int result = 0;

            int last_pos = 0;
            for (const auto w : word)
            {
                result += abs(pos[w - 'a'] - last_pos);
                last_pos = pos[w - 'a'];
            }

            return result;
        }
    };
}
