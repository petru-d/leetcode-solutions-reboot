#pragma once
#include <string>
#include <vector>
#include <array>

namespace p1684
{
    class Solution
    {
      public:
        int countConsistentStrings(std::string allowed, std::vector<std::string>& words)
        {
            std::array<size_t, 26> mask = {};
            for (const auto a : allowed)
                ++mask[a - size_t('a')];

            int result = 0;
            for (const auto& w : words)
            {
                bool ok = true;
                for (const auto l : w)
                {
                    ok = ok && (mask[l - size_t('a')] > 0);
                    if (!ok)
                        break;
                }

                result += int(ok);
            }

            return result;
        }
    };
}
