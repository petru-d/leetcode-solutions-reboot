#pragma once
#include <array>
#include <unordered_map>
#include <vector>

namespace p525
{
    // stolen solution: keep a running sum (decrese with 1 if encountering zero, increase for one).
    // when seeing zero, it means that we found a neutral array (which starts from index 0)
    // when seeing something we saw earlier, it means that the array in between the sights is neutral (equal numbers of zeros and
    // ones) when not seeing something non zero and new, remember where it was, for later
    class Solution
    {
      public:
        int findMaxLength(std::vector<int>& nums)
        {
            if (nums.empty())
                return 0;

            bool found_any = false;
            std::pair<size_t, size_t> best_interval;
            auto register_interval = [&best_interval, &found_any](const std::pair<size_t, size_t>& new_interval) {
                found_any = true;
                if (new_interval.second - new_interval.first > best_interval.second - best_interval.first)
                    best_interval = new_interval;
            };

            std::unordered_map<int16_t, size_t> sums;

            int16_t current_count = nums[0] == 0 ? -1 : 1;
            sums.insert({current_count, 0});

            size_t N = nums.size();
            for (size_t i = 1; i < N; ++i)
            {
                current_count += nums[i] == 0 ? -1 : 1;
                if (current_count == 0)
                {
                    register_interval({0, i});
                }
                else
                {
                    auto pos = sums.find(current_count);
                    if (pos == sums.end())
                    {
                        sums[current_count] = i;
                    }
                    else
                    {
                        register_interval({pos->second + 1, i});
                    }
                }
            }

            return found_any ? static_cast<int>(best_interval.second - best_interval.first + 1) : 0;
        }
    };
}