#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>

namespace code_chall_1_p1
{
    class Solution
    {
      public:
        int singleNumber(std::vector<int>& nums)
        {
            std::unordered_map<int, bool> pairs;

            for (auto n : nums)
            {
                auto pos = pairs.find(n);
                pairs[n] = (pos != pairs.end());
            }

            auto pos_single = std::find_if(pairs.begin(), pairs.end(), [](const auto& kv) { return !kv.second; });

            return pos_single->first;
        }
    };

    // shamelesly copied :(
    class Solution_stolen
    {
      public:
        int singleNumber(std::vector<int>& nums)
        {
            auto res = nums[0];
            auto N = nums.size();
            for (size_t i = 1; i < N; ++i)
            {
                res ^= nums[i];
            }

            return res;
        }
    };
}