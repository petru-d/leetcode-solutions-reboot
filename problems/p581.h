#pragma once
#include <algorithm>
#include <stack>
#include <vector>

namespace p581
{
    class Solution
    {
      public:
        int findUnsortedSubarray2(std::vector<int>& nums)
        {
            if (nums.empty())
                return 0;

            std::stack<int> s;
            s.push(nums[0]);

            int max = nums[0];

            size_t min_stack_len = -1;
            size_t right_index = -1;

            for (size_t i = 1; i < nums.size(); ++i)
            {
                if (nums[i] >= max)
                {
                    s.push(nums[i]);
                    max = nums[i];
                }
                else
                {
                    while (!s.empty() && s.top() > nums[i])
                        s.pop();
                    min_stack_len = std::min(min_stack_len, s.size());

                    if (s.empty() || s.top() < nums[i])
                        s.push(nums[i]);

                    right_index = i + 1;
                }
            }

            return static_cast<int>(right_index - min_stack_len);
        }

        int findUnsortedSubarray(std::vector<int>& nums)
        {
            if (nums.empty())
                return 0;

            int min_unsorted_zone = std::numeric_limits<int>::max();
            bool unsorted_zone = false;
            for (size_t i = 1; i < nums.size(); ++i)
            {
                if (nums[i] < nums[i - 1])
                    unsorted_zone = true;

                if (unsorted_zone)
                    min_unsorted_zone = std::min(min_unsorted_zone, nums[i]);
            }

            int max = nums[0];

            size_t right_index = -1;
            size_t left_index = nums[0] > min_unsorted_zone ? 0 : -1;

            for (size_t i = 1; i < nums.size(); ++i)
            {
                if (left_index == -1 && nums[i] > min_unsorted_zone)
                {
                    left_index = i;
                }

                if (nums[i] >= max)
                {
                    max = nums[i];
                }
                else
                {
                    right_index = i + 1;
                }
            }

            return static_cast<int>(right_index - left_index);
        }
    };
}
