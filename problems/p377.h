#pragma once

namespace p377
{
    class Solution
    {
      public:
        int combinationSum4(std::vector<int>& nums, int target)
        {
            // when solving for a number T,
            // each n in nums can take turns in being the last one in the solution for T
            // e.g. for [1,2,3] and 4
            // P(4) = union of P(4 - 1) followed by 3 +
            //        union of P(4 - 2) followed by 2 +
            //        union of P(4 - 3) followed by 1
            // or, differently said, we split the solutions for T into dijunct and complete classes according to their last
            // element
            std::vector<uint64_t> csum(target + 1, 0);
            csum[0] = 1;

            for (size_t i = 1; i <= size_t(target); ++i)
                for (auto n : nums)
                    if (i >= n)
                        csum[i] += csum[i - n];

            return csum[target];
        }
    };
}
