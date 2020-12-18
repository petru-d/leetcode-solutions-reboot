#pragma once

#include <vector>

namespace p605
{
    class Solution
    {
      public:
        bool canPlaceFlowers(std::vector<int>& flowerbed, int n)
        {
            int can_place = 0;

            bool during_gap = (flowerbed[0] == 0);
            bool edge_gap = during_gap;
            bool all_zeros = during_gap;
            size_t gap_start = (flowerbed[0] == 0) ? 0 : -1;
            size_t N = flowerbed.size();
            for (size_t i = 1; i < N; ++i)
            {
                if (flowerbed[i] == 1)
                {
                    if (during_gap)
                    {
                        during_gap = false;
                        can_place += place(i - gap_start, edge_gap);
                    }
                    all_zeros = false;
                }
                else
                {
                    if (!during_gap)
                    {
                        during_gap = true;
                        gap_start = i;
                        edge_gap = false;
                    }
                }
            }

            if (during_gap)
                can_place += (!all_zeros) ? place(N - gap_start, true) : place(N - gap_start);

            return can_place >= n;
        }

        int place(size_t gap_size, bool edge_gap)
        {
            if (gap_size <= 1)
                return 0;

            if (gap_size == 2)
                return int(edge_gap);

            if (!edge_gap)
                return place(gap_size - 2);
            else
                return place(gap_size - 1);
        }

        int place(size_t gap_size)
        {
            return int(gap_size / 2 + gap_size % 2);
        }
    };
}
