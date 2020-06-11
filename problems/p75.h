#pragma once

#include <vector>

namespace p75
{
    class Solution
    {
      public:
        void sortColors(std::vector<int>& nums)
        {
            size_t N = nums.size();

            size_t zero_s = 0;
            size_t zero_e = 0;
            size_t one_s = 0;
            size_t one_e = 0;
            size_t two_s = 0;
            size_t two_e = 0;

            for (size_t i = 0; i < N; ++i)
            {
                if (nums[i] == 0)
                {
                    nums[zero_e] = 0;
                    ++zero_e;

                    if (one_s != one_e)
                    {
                        nums[one_e] = 1;
                    }
                    else
                    {
                        ++one_s;
                    }
                    ++one_e;

                    if (two_s != two_e)
                    {
                        nums[two_e] = 2;
                    }
                    else
                    {
                        ++two_s;
                    }
                    ++two_e;
                }
                else if (nums[i] == 1)
                {
                    nums[one_e] = 1;
                    ++one_e;

                    if (two_s != two_e)
                    {
                        nums[two_e] = 2;
                    }
                    else
                    {
                        ++two_s;
                    }
                    ++two_e;
                }
                else if (nums[i] == 2)
                {
                    // not needed to assign nums[two_e] = 2 since we're already there
                    ++two_e;
                }
            }
        }
    };
}
