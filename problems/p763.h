#pragma once
#include <algorithm>
#include <array>
#include <string>
#include <vector>

namespace p763
{
    class Solution
    {
      public:
        std::vector<int> partitionLabels(std::string S)
        {
            size_t SS = S.size();
            if (SS <= 1)
                return {int(SS)};

            struct Range
            {
                size_t start = std::numeric_limits<size_t>::max();
                size_t end = std::numeric_limits<size_t>::min();
            };

            std::array<Range, 26> letterRanges;
            for (size_t i = 0; i < SS; ++i)
            {
                letterRanges[S[i] - 'a'].start = std::min(letterRanges[S[i] - 'a'].start, i);
                letterRanges[S[i] - 'a'].end = std::max(letterRanges[S[i] - 'a'].end, i + 1);
            }

            std::sort(letterRanges.begin(), letterRanges.end(), [](const Range& l, const Range& r) { return l.start < r.start; });

            std::vector<int> result;

            Range latest = letterRanges[0];
            for (size_t i = 1; i < 26; ++i)
            {
                if (letterRanges[i].start == std::numeric_limits<size_t>::max())
                    break;

                const auto& curr = letterRanges[i];
                if (curr.start < latest.end)
                    latest.end = std::max(latest.end, curr.end);
                else
                {
                    result.push_back(static_cast<int>(latest.end - latest.start));
                    latest = curr;
                }
            }
            result.push_back(static_cast<int>(latest.end - latest.start));

            return result;
        }
    };
}
