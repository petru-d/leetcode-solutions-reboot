#pragma once
#include <vector>

namespace p849
{
    class Solution
    {
      public:
        int maxDistToClosest(std::vector<int>& seats)
        {
            // find the biggest gap, sit in the middle
            // start and end gaps are special, since one can sit at the end of the gap

            std::pair<size_t, size_t> biggest_gap = {0, 0};
            std::pair<size_t, size_t> start_gap = {0, 0};
            std::pair<size_t, size_t> end_gap = {0, 0};

            // find the starting gap (if any)
            size_t start_gap_end = 0;
            while (seats[start_gap_end] == 0)
                ++start_gap_end;
            start_gap = {0, start_gap_end};

            // keep the "best gap" from the middle ones
            std::pair<size_t, size_t> curr_gap = {0, 0};
            auto S = seats.size();
            for (size_t i = start_gap_end; i < S; ++i)
            {
                if (seats[i] == 0 && seats[i - 1] == 1)
                    curr_gap.first = i;

                if (seats[i] == 1 && i > 0 && seats[i - 1] == 0)
                {
                    curr_gap.second = i;
                    if (curr_gap.second - curr_gap.first > biggest_gap.second - biggest_gap.first)
                        biggest_gap = curr_gap;
                }
            }

            // close the last gap, keep end gap (if any)
            if (seats[S - 1] == 0)
            {
                curr_gap.second = S;
                end_gap = curr_gap;
                if (curr_gap.second - curr_gap.first > biggest_gap.second - biggest_gap.first)
                    biggest_gap = curr_gap;
            }

            return static_cast<int>(std::max({start_gap.second - start_gap.first, end_gap.second - end_gap.first,
                                              (biggest_gap.second - biggest_gap.first - 1) / 2 + 1},
                                             std::less<size_t>()));
        }
    };
}