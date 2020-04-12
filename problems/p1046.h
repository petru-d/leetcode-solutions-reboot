#pragma once
#include <algorithm>
#include <vector>

namespace p1046
{
    class Solution
    {
      public:
        int lastStoneWeight(std::vector<int>& stones)
        {
            std::make_heap(stones.begin(), stones.end());

            while (stones.size() >= 2)
            {
                std::pop_heap(stones.begin(), stones.end());
                int max1 = stones.back();
                stones.pop_back();

                std::pop_heap(stones.begin(), stones.end());
                int max2 = stones.back();
                stones.pop_back();

                if (max1 != max2)
                {
                    stones.push_back(max1 - max2);
                    std::push_heap(stones.begin(), stones.end());
                }
            }

            if (stones.empty())
                return 0;

            return stones.front();
        }
    };
}