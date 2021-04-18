#pragma once
#include <algorithm>
#include <vector>

namespace p1465
{
    class Solution
    {
      public:
        int maxArea(int h, int w, std::vector<int>& horizontalCuts, std::vector<int>& verticalCuts)
        {
            std::sort(horizontalCuts.begin(), horizontalCuts.end());
            std::sort(verticalCuts.begin(), verticalCuts.end());

            int max_h = horizontalCuts[0];
            size_t H = horizontalCuts.size();
            for (size_t i = 1; i < H; ++i)
                max_h = std::max(max_h, horizontalCuts[i] - horizontalCuts[i - 1]);
            max_h = std::max(max_h, h - horizontalCuts.back());

            int max_w = verticalCuts[0];
            size_t W = verticalCuts.size();
            for (size_t i = 1; i < W; ++i)
                max_w = std::max(max_w, verticalCuts[i] - verticalCuts[i - 1]);
            max_w = std::max(max_w, w - verticalCuts.back());

            constexpr int mod = 1000000007;

            return uint64_t(max_h) * max_w % mod;
        }
    };
}
