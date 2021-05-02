#pragma once
#include <vector>

namespace p1229
{
    class Solution
    {
      public:
        // can also put everything in a min prio queue and check overlap on the top 2 elements
        // if the second smallest overlaps with the smallest, they are guaranteed to be from different arrays and they are the
        // answer
        std::vector<int> minAvailableDuration(std::vector<std::vector<int>>& slots1, std::vector<std::vector<int>>& slots2,
                                              int duration)
        {
            auto lessSlots = [](const std::vector<int>& l, const std::vector<int>& r) { return l[1] < r[0]; };
            std::sort(slots1.begin(), slots1.end(), lessSlots);
            std::sort(slots2.begin(), slots2.end(), lessSlots);

            auto getOverlap = [](int start1, int end1, int start2, int end2) {
                return std::pair<int, int>(std::max(start1, start2), std::min(end1, end2));
            };

            auto S1 = slots1.size();
            auto S2 = slots2.size();
            size_t pos1 = 0;
            size_t pos2 = 0;
            while (pos1 < S1 && pos2 < S2)
            {
                const auto start1 = slots1[pos1][0];
                const auto end1 = slots1[pos1][1];
                const auto start2 = slots2[pos2][0];
                const auto end2 = slots2[pos2][1];

                if (end1 - start1 < duration)

                    // first interval ends before the second starts or the first interval is too small
                    if ((end1 < start2) || (end1 - start1 < duration))
                    {
                        ++pos1;
                        continue;
                    }

                // second interval ends before the first starts or the second interval is too small
                if ((end2 < start1) || (end2 - start2 < duration))
                {
                    ++pos2;
                    continue;
                }

                // we have some overlap - test if it is enough
                auto [overlapStart, overlapEnd] = getOverlap(start1, end1, start2, end2);
                if (overlapEnd - overlapStart >= duration)
                    return {overlapStart, overlapStart + duration};

                // not enough overlap - if we are at the end of a list, advance in the other
                if (pos1 == S1 - 1)
                {
                    if (start2 > end1)
                        return {};
                    ++pos2;
                    continue;
                }
                if (pos2 == S2 - 1)
                {
                    if (start1 > end2)
                        return {};
                    ++pos1;
                    continue;
                }

                // not enough overlap, not at the end of any list - advance in the list with the earliest start
                const auto next_start_1 = slots1[pos1 + 1][0];
                const auto next_start_2 = slots2[pos2 + 1][0];

                if (next_start_1 <= next_start_2)
                    ++pos1;
                else
                    ++pos2;
            }

            return {};
        }
    };
}
