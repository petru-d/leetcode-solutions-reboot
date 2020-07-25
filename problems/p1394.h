#pragma once

#include <algorithm>
#include <unordered_map>
#include <vector>

namespace p1394
{
    class Solution
    {
      public:
        int findLucky(std::vector<int>& arr)
        {
            int N = static_cast<int>(arr.size());
            std::unordered_map<int, int> occurences;
            std::set<int> luckyes;
            for (const auto n : arr)
            {
                if (n < 0 || n > N)
                    continue;
                auto& occ = occurences[n];
                ++occ;
                if (occ == n)
                    luckyes.insert(n);
                if (occ > n)
                    luckyes.erase(n);
            }

            return luckyes.empty() ? -1 : *luckyes.rbegin();
        }
    };
}
