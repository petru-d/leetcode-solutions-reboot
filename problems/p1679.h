#pragma once
#include <vector>
#include <unordered_map>

namespace p1679
{
    class Solution
    {
      public:
        int maxOperations(std::vector<int>& nums, int k)
        {
            std::unordered_map<int, int> small;
            std::unordered_map<int, int> big;
            int halves = 0;

            for (const auto n : nums)
            {
                if (n < (k / 2.))
                    ++small[n];
                else if (n > (k / 2.))
                    ++big[n];
                else if (n == k / 2 && k % 2 == 0)
                    ++halves;
            }

            int result = halves / 2;
            for (const auto [sk, sv] : small)
            {
                auto pos = big.find(k - sk);
                if (pos != big.end())
                    result += std::min(sv, pos->second);
            }

            return result;
        }
    };
}
