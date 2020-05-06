#pragma once
#include <unordered_map>
#include <vector>

namespace p169
{
    class Solution
    {
      public:
        // better approach: Boyer-Moore voting
        int majorityElement(std::vector<int>& nums)
        {
            std::unordered_map<int, size_t> occurences;
            for (auto n : nums)
            {
                ++occurences[n];
            }

            for (auto [k, v] : occurences)
            {
                if (v > nums.size() / 2)
                    return k;
            }

            return -1;
        }
    };
}