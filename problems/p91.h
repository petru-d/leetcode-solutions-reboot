#pragma once
#include <string>

namespace p91
{
    class Solution
    {
      public:
        int numDecodings(std::string s)
        {
            std::vector<int> ways(s.size() + 1, 0);
            ways[s.size()] = 1;
            ways[s.size() - 1] = s.back() == '0' ? 0 : 1;

            auto ok = [](int digit) { return digit != 0; };
            auto ok2 = [](int digit, int next_digit) {
                if (digit == 1)
                    return true;
                if (digit == 2)
                    return 0 <= next_digit && next_digit <= 6;
                return false;
            };

            for (size_t i = s.size() - 1; i > 0; --i)
            {
                auto digit = s[i - 1] - '0';
                auto next_digit = s[i] - '0';

                if (ok(digit))
                    ways[i - 1] = ways[i];
                if (ok2(digit, next_digit))
                    ways[i - 1] += ways[i + 1];
            }

            return ways[0];
        }
    };
}
