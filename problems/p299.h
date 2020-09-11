#pragma once
#include <array>
#include <string>

namespace p299
{
    class Solution
    {
      public:
        std::string getHint(std::string secret, std::string guess)
        {
            std::array<size_t, 10> c1 = {};
            std::array<size_t, 10> c2 = {};

            size_t bulls = 0;
            size_t cows = 0;

            size_t N = secret.size();
            for (size_t i = 0; i < N; ++i)
            {
                if (secret[i] == guess[i])
                {
                    ++bulls;
                    continue;
                }

                ++c1[secret[i] - '0'];
                ++c2[guess[i] - '0'];
            }

            for (size_t i = 0; i < 10; ++i)
                cows += std::min(c1[i], c2[i]);

            return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
        }
    };
}
