#pragma once
#include <vector>

namespace p673
{
    class Solution
    {
      public:
        int findNumberOfLIS(std::vector<int>& nums)
        {
            size_t N = nums.size();
            if (N == 0)
                return 0;

            std::vector<std::pair<size_t, size_t>> seq(N, {1, 1});

            for (size_t i = 1; i < N; ++i)
            {
                auto ni = nums[i];
                size_t maxlen = 0;
                size_t maxcnt = 1;
                for (size_t k = 0; k < i; ++k)
                    if (ni > nums[k])
                    {
                        if (maxlen == seq[k].first)
                            maxcnt += seq[k].second;
                        else if (maxlen < seq[k].first)
                        {
                            maxlen = seq[k].first;
                            maxcnt = seq[k].second;
                        }
                    }
                seq[i] = {1 + maxlen, maxcnt};
            }

            size_t maxlen = seq[0].first;
            size_t maxcnt = seq[0].second;

            for (size_t i = 1; i < N; ++i)
            {
                if (maxlen == seq[i].first)
                    maxcnt += seq[i].second;
                else if (maxlen < seq[i].first)
                {
                    maxlen = seq[i].first;
                    maxcnt = seq[i].second;
                }
            }

            return int(maxcnt);
        }
    };
}
