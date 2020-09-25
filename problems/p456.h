#pragma once
#include <algorithm>
#include <stack>
#include <vector>

namespace p456
{
    // my solution:
    /*
    class Solution
    {
      public:
        bool find132pattern(std::vector<int>& nums)
        {
            size_t N = nums.size();
            if (N < 3)
                return false;

            std::vector<size_t> lows;
            std::vector<size_t> highs;

            size_t first_low = 0;
            for (size_t i = 1; i < N; ++i)
                if (nums[i] < nums[i - 1])
                    ++first_low;
                else
                    break;

            if (first_low >= N - 2)
                return false;

            lows.push_back(first_low);
            highs.push_back(first_low + 1);
            for (size_t i = first_low + 2; i < N; ++i)
            {
                auto curr = nums[i];

                if (nums[lows.back()] < curr && curr < nums[highs.back()])
                    return true;

                if (curr > nums[highs.back()])
                    highs.back() = i;
                else if (curr < nums[lows.back()])
                {
                    lows.push_back(i);
                    highs.push_back(i);
                }
            }

            for (size_t i = N; i > 0; --i)
            {
                for (size_t lh = 0; lh < lows.size(); ++lh)
                {
                    if (highs[lh] >= i - 1)
                        break;

                    if (nums[lows[lh]] < nums[i - 1] && nums[i - 1] < nums[highs[lh]])
                        return true;
                }
            }

            return false;
        }
    };
    */

    // re-implemented lc solution
    class Solution
    {
      public:
        bool find132pattern(std::vector<int>& nums)
        {
            size_t N = nums.size();
            if (N < 3)
                return false;

            // for each number at index j, keep it's best candidate for index "i"
            // note that best_i will be sorted descendingly by construction
            std::vector<int> best_i(N, 0);
            best_i[0] = nums[0];
            for (size_t i = 1; i < N; ++i)
                best_i[i] = std::min(best_i[i - 1], nums[i]);

            std::stack<int> s;

            for (size_t j = N; j > 0; --j)
            {
                if (nums[j - 1] <= best_i[j - 1])
                    continue;

                // search for an element on the stack that's greater than best_i[j]
                // Note: discarding an element is safe. if it's not good now, it will not be good later, because best_i is
                // descending.
                while (!s.empty() && s.top() <= best_i[j - 1])
                    s.pop();
                // if the stack is not empty, then it's top is greater than best_i[j] (see above)
                // if the top is also smaller than nums[j], we found an 132 pattern (traversing from the back)
                if (!s.empty() && s.top() < nums[j - 1])
                    return true;

                // stack is empty or its top is greater than nums[j]. pushing nums[j] will keep it sorted
                // this means, next time when we will pop, we will pop numbers in ascending order,
                // guaranteening we will find the smallest number greater than best_i[next j]
                s.push(nums[j - 1]);
            }

            // tricky stuff

            return false;
        }
    };
}
