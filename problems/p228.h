#pragma once
#include <vector>
#include <string>

namespace p228
{
    class Solution
    {
      public:
        std::vector<std::string> summaryRanges(std::vector<int>& nums)
        {
            auto N = nums.size();
            if (N == 0)
                return {};

            auto make_res = [](int s, int e) {
                return s == e ? std::to_string(s) : (std::to_string(s) + "->" + std::to_string(e));
            };

            std::vector<std::string> result;

            int curr = nums[0];
            for (size_t i = 1; i < N; ++i)
            {
                if (nums[i] != nums[i - 1] + 1)
                {
                    result.push_back(make_res(curr, nums[i - 1]));
                    curr = nums[i];
                }
            }
            result.push_back(make_res(curr, nums[N - 1]));

            return result;
        }
    };
}
