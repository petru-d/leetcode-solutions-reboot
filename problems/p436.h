#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

namespace p436
{
    class Solution
    {
      public:
        std::vector<int> findRightInterval(std::vector<std::vector<int>>& intervals)
        {
            size_t N = intervals.size();
            if (N == 0)
                return {};

            std::vector<size_t> indexes(N, 0);
            std::iota(indexes.begin(), indexes.end(), 0);

            std::sort(indexes.begin(), indexes.end(),
                      [&intervals](size_t li, size_t ri) { return intervals[li][0] < intervals[ri][0]; });

            std::vector<int> result(N, -1);
            for (size_t i = 0; i < N; ++i)
            {
                auto pos = std::partition_point(indexes.begin() + i + 1, indexes.end(), [i, &intervals, &indexes](size_t index) {
                    bool gt = intervals[indexes[i]][1] > intervals[index][0];
                    return gt;
                });

                result[indexes[i]] = (pos == indexes.end() ? -1 : static_cast<int>(*pos));
            }

            return result;
        }
    };
}
