#pragma once
#include <unordered_map>
#include <vector>

namespace p594
{
    class Solution
    {
      public:
        int findLHS(std::vector<int>& nums)
        {
            std::unordered_map<int, size_t> loners;
            size_t max = 0;

            for (const auto& n : nums)
            {
                size_t n_quant = 0;
                auto pos_lone = loners.find(n);
                if (pos_lone == loners.end())
                {
                    loners.insert({n, 1});
                    n_quant = 1;
                }
                else
                {
                    ++pos_lone->second;
                    n_quant = pos_lone->second;
                }

                auto pos_lone_low = loners.find(n - 1);
                if (pos_lone_low != loners.end())
                    max = std::max(max, pos_lone_low->second + n_quant);

                auto pos_lone_high = loners.find(n + 1);
                if (pos_lone_high != loners.end())
                    max = std::max(max, pos_lone_high->second + n_quant);
            }

            return max;
        }
    };
}
