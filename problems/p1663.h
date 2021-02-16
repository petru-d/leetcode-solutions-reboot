#pragma once
#include <string>

namespace p1663
{
    class Solution
    {
      public:
        std::string getSmallestString(int n, int k)
        {
            // we need to make this up by changing some a to z
            int diff = k - n;

            // for each change, we get 25 points
            auto [q, r] = std::div(diff, 25);

            // n - q - 1 times letter 'a' (add one 'a' for r == 0)
            // 1 time letter with rank r + 1 (only if r != 0)
            // q times 'z'

            std::string result;
            result.reserve(n);
            for (int i = 0; i < n - q - 1 + (r == 0); ++i)
                result.push_back('a');
            if (r != 0)
                result.push_back('a' + r);
            for (int i = 0; i < q; ++i)
                result.push_back('z');

            return result;
        }
    };
}
