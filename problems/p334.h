#pragma once
#include <vector>
#include <optional>

namespace p334
{
    class Solution
    {
      public:
        bool increasingTriplet(std::vector<int>& nums)
        {
            std::optional<int> low_big = {};
            std::optional<int> high_big = {};
            std::optional<int> low_alone = {};

            for (const auto n : nums)
            {
                if (!low_big)
                {
                    low_big = n;
                    continue;
                }

                if (!high_big)
                {
                    if (n <= low_big.value())
                        low_big = n;
                    else
                        high_big = n;
                    continue;
                }

                if (n > high_big)
                    return true;

                if (!low_alone)
                {
                    low_alone = n;
                    continue;
                }

                // have low_big, high_big and low_alone in this order
                // low_alone < low_big < high_big
                // current element n <= high_big
                if (n > low_big)
                    high_big = n;
                else if (n > low_alone)
                {
                    low_big = low_alone;
                    high_big = n;
                    low_alone = {};
                }
                else
                {
                    low_alone = n;
                }
            }

            return false;
        }
    };
}
