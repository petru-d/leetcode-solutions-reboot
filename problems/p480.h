#pragma once
#include <set>
#include <vector>

namespace p480
{
    class Solution
    {
      public:
        std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k)
        {
            std::vector<double> result;

            std::multiset<int> small;
            std::multiset<int> big;

            for (size_t i = 0; i < nums.size(); ++i)
            {
                if (i >= k)
                {
                    auto to_remove = nums[i - k];
                    if (to_remove <= *small.rbegin())
                        small.erase(small.find(to_remove));
                    else
                        big.erase(big.find(to_remove));
                }

                small.insert(nums[i]);
                big.insert(*small.rbegin());
                small.erase(prev(small.end()));

                if (small.size() < big.size())
                {
                    small.insert(*big.begin());
                    big.erase(big.begin());
                }

                if (i >= k - 1)
                {
                    if (k % 2 == 1)
                        result.push_back(*small.rbegin());
                    else
                        result.push_back((double(*small.rbegin()) + double(*big.begin())) / 2);
                }
            }

            return result;
        }
    };
}
