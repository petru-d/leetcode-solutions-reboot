#pragma once
#include <algorithm>
#include <array>

namespace p869
{
    class Solution
    {
      public:
        constexpr std::array<size_t, 10> extract(int n)
        {
            std::array<size_t, 10> res = {};
            while (n)
            {
                auto [q, r] = std::div(n, 10);
                n = q;
                ++res[r];
            }
            return res;
        }

        constexpr std::array<std::array<size_t, 10>, 32> MakeArrays()
        {
            std::array<std::array<size_t, 10>, 32> res = {};

            int curr = 1;
            size_t pos = 0;
            while (true)
            {
                res[pos++] = extract(curr);
                if (curr > std::numeric_limits<int>::max() / 2)
                    break;
                curr *= 2;
            }

            return res;
        }

        bool reorderedPowerOf2(int N)
        {
            auto arrs = MakeArrays();

            auto arrN = extract(N);

            return std::find(arrs.begin(), arrs.end(), arrN) != arrs.end();
        }
    };
}
