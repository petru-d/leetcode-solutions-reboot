#pragma once
#include <vector>

namespace p1510
{
    class Solution
    {
      public:
        bool winnerSquareGame(int n)
        {
            std::vector<bool> win(size_t(n) + 1, false);
            std::vector<bool> ok(size_t(n) + 1, false);

            auto set = [&win, &ok](bool val, size_t i) {
                win[i] = val;
                ok[i] = true;
            };

            auto SQN = sqrt(n);
            for (size_t i = 1; i <= SQN; ++i)
            {
                set(true, i * i);
            }

            for (size_t i = 1; i <= n; ++i)
            {
                if (ok[i])
                    continue;

                for (size_t j = 1; j < sqrt(i); ++j)
                    if (!win[i - j * j])
                    {
                        set(true, i);
                        break;
                    }
            }

            return win[n];
        }
    };
}
