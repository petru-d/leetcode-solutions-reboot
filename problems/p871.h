#pragma once

#include <algorithm>
#include <queue>
#include <vector>

namespace p871
{
    class Solution
    {
      public:
        int minRefuelStops_dp(int target, int startFuel, std::vector<std::vector<int>>& st)
        {
            size_t N = st.size();
            // longest range with k stops
            std::vector<uint64_t> range_k_stops(N + 1, 0);

            // with zero stops, the range is <startFuel>
            range_k_stops[0] = startFuel;

            // For each station s, update the ranges with "k" stops.
            // - k is at most s + 1, because this is the maximum amount of stops we can do up and including station with index s
            //   (zero based)
            // - k is at least 1, because updating the range with zero stops makes no sense.
            // - need to go backwards, since going forward changes the range [k] which will mess up the range check for [k + 1] !
            for (size_t s = 0; s < N; ++s)
            {
                for (size_t k = s + 1; k >= 1; --k)
                    // for (size_t k = 1; k <= s + 1; ++k)
                    if (range_k_stops[k - 1] >= st[s][0])
                        range_k_stops[k] = std::max(range_k_stops[k], range_k_stops[k - 1] + st[s][1]);
            }

            auto pos =
                std::find_if(range_k_stops.begin(), range_k_stops.end(), [target](uint64_t range) { return range >= target; });

            return pos != range_k_stops.end() ? static_cast<int>(std::distance(range_k_stops.begin(), pos)) : -1;
        }

        int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>>& st)
        {
            st.push_back({target, 0});

            size_t N = st.size();

            std::priority_queue<int> reserves;

            int refuels = 0;

            int total = startFuel;
            int prev_pos = 0;
            for (size_t i = 0; i < N; ++i)
            {
                total -= st[i][0] - prev_pos;
                while (total < 0 && !reserves.empty())
                {
                    int biggest_refuel = reserves.top();
                    reserves.pop();
                    total += biggest_refuel;
                    ++refuels;
                }

                if (total < 0)
                    return -1;

                reserves.push(st[i][1]);
                prev_pos = st[i][0];
            }

            return refuels;
        }
    };
}
