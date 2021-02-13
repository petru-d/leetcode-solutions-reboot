#pragma once
#include <unordered_map>
#include <vector>

namespace p1713
{
    // This is a Longest Common Sequence problem. 
    // However, since the numbers are distinct, we can transform it into a LIS problem, but based on array indices.
    class Solution
    {
      public:
        int minOperations(std::vector<int>& target, std::vector<int>& arr)
        {
            std::unordered_map<int, size_t> target_to_index;

            auto T = target.size();
            for (size_t i = 0; i < T; ++i)
                target_to_index[target[i]] = i;

            std::vector<size_t> arr_index;
            arr_index.reserve(T);

            for (const auto& a : arr)
            {
                auto pos = target_to_index.find(a);
                if (pos != target_to_index.end())
                    arr_index.push_back(pos->second);
            }

            return static_cast<int>(target.size() - lis(arr_index));
        }
        // patience sorting, but keeping only the tops of the piles
        size_t lis(const std::vector<size_t>& arr)
        {
            std::vector<size_t> piles;
            for (const auto a : arr)
            {
                auto pos = std::lower_bound(piles.begin(), piles.end(), a);
                if (pos != piles.end())
                {
                    *pos = a;
                }
                else
                {
                    piles.push_back(a);
                }
            }

            return piles.size();
        }
    };
}
