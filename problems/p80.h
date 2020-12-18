#pragma once
#include <vector>

namespace p80
{
    class Solution
    {
      public:
        int removeDuplicates(std::vector<int>& nums)
        {
            auto N = nums.size();
            if (N < 3)
                return int(N);

            size_t last_good = 1;
            for (size_t curr = 2; curr < N; ++curr)
            {
                if (nums[curr] != nums[last_good - 1])
                {
                    nums[++last_good] = nums[curr];
                }
                else
                {
                    while (curr < N && nums[curr] == nums[last_good - 1])
                        ++curr;

                    if (curr == N)
                        break;

                    nums[++last_good] = nums[curr];
                }
            }

            return int(last_good) + 1;
        }
    };
}
