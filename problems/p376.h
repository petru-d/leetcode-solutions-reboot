#pragma once

#include <vector>
namespace p376
{
    class Solution
    {
      public:
        int wiggleMaxLength(std::vector<int>& nums)
        {
            auto N = nums.size();
            if (N <= 1)
                return static_cast<int>(N);

            size_t i = 1;
            while (i < N && nums[i] == nums[0])
                ++i;
            if (i == N)
                return 1;

            int total = 2;
            bool up = (nums[i] - nums[0] > 0);
            for (size_t j = i + 1; j < N; ++j)
            {
                if (up)
                {
                    while (up && j < N && (nums[j] - nums[j - 1] >= 0))
                        ++j;

                    if (j >= N)
                        break;
                    up = false;
                    ++total;
                }
                else
                {
                    while (!up && j < N && (nums[j] - nums[j - 1] <= 0))
                        ++j;
                    if (j >= N)
                        break;
                    up = true;
                    ++total;
                }
            }

            return total;
        }
    };
}