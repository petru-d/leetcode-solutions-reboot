#pragma once
#include <array>
#include <string>

namespace p246
{
    class Solution
    {
      public:
        bool isStrobogrammatic(std::string num)
        {
            std::array<char, 10> inverses = {'0', '1', 0, 0, 0, 0, '9', 0, '8', '6'};

            auto N = num.size();
            for (size_t i = 0; i <= N / 2; ++i)
            {
                if (inverses[num[i] - '0'] == 0)
                    return false;

                if (num[i] != inverses[num[N - i - 1] - '0'])
                    return false;
            }

            return true;
        }
    };
}
