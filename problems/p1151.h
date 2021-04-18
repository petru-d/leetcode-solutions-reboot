#pragma once
#include <vector>

namespace p1151
{
    class Solution
    {
      public:
        int minSwaps(std::vector<int>& data)
        {
            // if C1 is the number of ones,
            // make a sliding window of size C1 and slide it across the data.
            // the minimum number of zeros in the window is the answer
            auto C1 = std::count(data.begin(), data.end(), 1);
            if (C1 <= 1)
                return 0;
            auto D = data.size();

            size_t window_start = 0;
            size_t window_end = C1;
            auto curr_zero_count = std::count(data.begin(), data.begin() + C1, 0);
            auto best = curr_zero_count;

            while (window_end < D)
            {
                curr_zero_count -= (data[window_start] == 0);
                curr_zero_count += (data[window_end] == 0);

                best = std::min(best, curr_zero_count);
                if (best == 1)
                    return 1;

                ++window_start;
                ++window_end;
            }

            return int(best);
        }
    };
}
