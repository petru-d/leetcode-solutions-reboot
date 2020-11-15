#pragma once
#include <vector>
#include <deque>

namespace p239
{
    class Solution
    {
      public:
        /*vector<int> maxSlidingWindow(vector<int>& nums, int k)
        {
            size_t N = nums.size();

            std::vector<int> result;
            result.reserve(N - k + 1);

            std::multiset<int> win;
            for (size_t i = 0; i < k; ++i)
                win.insert(nums[i]);
            result.push_back(*win.rbegin());

            for (size_t i = 0; i < N - k; ++i)
            {
                //nums[i] leaves, nums[i + k] enters

                auto hit(win.find(nums[i]));
                win.erase(hit);
                win.insert(nums[i + k]);
                result.push_back(*win.rbegin());
            }

            return result;
        }*/

        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
        {
            size_t N = nums.size();

            std::vector<int> result;
            result.reserve(N - k + 1);

            std::deque<int> win;

            auto add = [&win](int val) {
                while (!win.empty() && val > win.back())
                    win.pop_back();
                win.push_back(val);
            };

            for (size_t i = 0; i < k; ++i)
                add(nums[i]);
            result.push_back(win.front());

            for (size_t i = 0; i < N - k; ++i)
            {
                if (nums[i] >= win.front())
                    win.pop_front();
                add(nums[i + k]);

                result.push_back(win.front());
            }

            return result;
        }
    };
}
