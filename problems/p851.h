#pragma once
#include <limits>
#include <stack>
#include <vector>

namespace p851
{
    class Solution
    {
      public:
        int findUnsortedSubarray_mine(std::vector<int>& nums)
        {
            std::stack<std::pair<int, size_t>> s;
            s.push({nums[0], 0});

            size_t low = std::numeric_limits<size_t>::max();
            size_t high = std::numeric_limits<size_t>::min();

            int max = nums[0];

            size_t N = nums.size();
            for (size_t i = 1; i < N; ++i)
            {
                if (nums[i] < max)
                {
                    high = i;
                    while (!s.empty() && s.top().first > nums[i])
                    {
                        low = std::min(low, s.top().second);
                        s.pop();
                    }
                }

                max = std::max(max, nums[i]);
                s.push({nums[i], i});
            }

            return low == std::numeric_limits<size_t>::max() ? 0 : 1 + high - low;
        }

        int findUnsortedSubarray_leetcode(std::vector<int>& nums)
        {
            auto S = nums.size();
            if (S <= 1)
                return 0;

            int max = std::numeric_limits<int>::min();
            size_t end = -1;
            // iterate from beginning of array
            // find the last element which is smaller than the last seen max from its left side and mark it as end
            for (size_t i = 0; i < S; ++i)
            {
                max = std::max(max, nums[i]);
                if (nums[i] < max)
                    end = i;
            }

            if (end == -1)
                return 0;

            int min = std::numeric_limits<int>::max();
            int begin = -1;
            // iterate from end of array
            // find the last element which is bigger than the last seen min from its right side and mark it as begin
            for (size_t i = S; i > 0; --i)
            {
                min = std::min(min, nums[i - 1]);
                if (nums[i - 1] > min)
                    begin = i - 1;
            }

            return end - begin + 1;
        }
    };
}
