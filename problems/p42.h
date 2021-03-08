#pragma once
#include <vector>
namespace p42
{
    class Solution
    {
      public:
        // for every point, calculate the amount of water above it
        // this is the diff between the value at that point and the min (max from left, max from right)
        // keeping left and right pointers we can calculate this without using extra space
        int trap(std::vector<int>& height)
        {
            auto N = height.size();
            if (N == 0)
                return 0;

            size_t l = 0;
            size_t r = N - 1;
            int max_l = height[l];
            int max_r = height[r];

            int res = 0;
            while (l < r)
            {
                int curr_height = 0;
                if (height[l] <= height[r])
                {
                    curr_height = height[l];
                    if (height[l] >= max_l)
                        max_l = height[l];
                    else
                        // h[l] <= h[r] so there is something holding the water on the right
                        res += max_l - height[l];
                    ++l;
                }
                else
                {
                    if (height[r] >= max_r)
                        max_r = height[r];
                    else
                        // h[r] < h[l] so there is something holding the water on the left
                        res += max_r - height[r];
                    --r;
                }
            }

            return res;
        }
    };
}
