#pragma once
#include <unordered_set>
#include <vector>
namespace p217
{
    class Solution
    {
      public:
        bool containsDuplicate(std::vector<int>& nums)
        {
            std::unordered_set<int> nums_unique;
            for (const auto n : nums)
            {
                auto [it, ok] = nums_unique.insert(n);
                if (!ok)
                    return true;
            }

            return false;
        }
    };
}
