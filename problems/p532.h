#pragma once
#include <unordered_map>
#include <vector>

namespace p532
{
    class Solution
    {
      public:
        int findPairs(std::vector<int>& nums, int k)
        {
            std::unordered_map<int, int> ncounted;

            for (auto n : nums)
                ++ncounted[n];

            int result = 0;
            for (const auto& [num, occ] : ncounted)
            {
                if (k != 0)
                {
                    auto pos_numplusk = ncounted.find(num + k);
                    result += (pos_numplusk != ncounted.end());
                }
                else
                    result += (occ >= 2);
            }
            return result;
        }
    };
}
