#pragma once
#include <queue>
#include <vector>
namespace p1642
{
    class Solution
    {
      public:
        int furthestBuilding(std::vector<int>& heights, int bricks, int ladders)
        {
            // can reach k-th building (say there are N climbs till then) if
            // sum of (<N - ladders> smallest climbs) <= bricks

            int available_bricks = bricks;
            std::priority_queue<int, std::vector<int>, std::greater<int>> used_ladders;

            auto H = heights.size();
            size_t L = size_t(ladders);
            for (size_t i = 1; i < H; ++i)
            {
                if (heights[i] <= heights[i - 1])
                    continue;

                if (used_ladders.size() < L)
                {
                    used_ladders.push(heights[i] - heights[i - 1]);
                    continue;
                }

                used_ladders.push(heights[i] - heights[i - 1]);

                auto smallest_gap = used_ladders.top();

                available_bricks -= smallest_gap;

                if (available_bricks < 0)
                    return i - 1;

                used_ladders.pop();
            }

            return H - 1;
        }
    };
}
