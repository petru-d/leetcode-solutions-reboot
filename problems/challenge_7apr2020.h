#pragma once
#include <unordered_set>
#include <vector>

namespace challenge_7apr2020
{
    // alternative solution: allocate std::array<bool, 1000> which is true at pos [i] iff arr contains i (perfect hash);
    // traverse arr again and look in hash to see if arr[i] + 1 is present
    class Solution
    {
      public:
        int countElements(std::vector<int>& arr)
        {
            std::unordered_set<int> as_set;
            for (auto a : arr)
                as_set.insert(a);

            int count = 0;
            for (auto a : arr)
            {
                if (as_set.find(a + 1) != as_set.end())
                    ++count;
            }

            return count;
        }
    };
}