#pragma once

namespace p442
{
    class Solution
    {
      public:
        std::vector<int> findDuplicates(std::vector<int>& nums)
        {
            int N = int(nums.size());
            for (int i = 0; i < N; ++i)
            {
                while (nums[i] != i + 1)
                {
                    if (nums[i] != nums[nums[i] - 1])
                        std::swap(nums[i], nums[nums[i] - 1]);
                    else
                        break;
                }
            }

            std::vector<int> result;
            for (int i = 0; i < N; ++i)
            {
                if (nums[i] != i + 1)
                    result.push_back(nums[i]);
            }

            return result;
        }
    };
}
