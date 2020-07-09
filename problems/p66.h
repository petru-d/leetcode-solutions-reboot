#pragma once
#include <vector>

namespace p66
{
    class Solution
    {
      public:
        std::vector<int> plusOne(std::vector<int>& i)
        {
            auto N = i.size();
            if (N == 0)
                return {};

            int over = 0;
            for (auto it = std::rbegin(i); it != std::rend(i); ++it)
            {
                auto qr = std::div(*it + 1, 10);
                over = qr.quot;
                *it = qr.rem;
                if (over == 0)
                    break;
            }

            if (over != 0)
            {
                i[0] = 1;
                i.push_back(0);
            }

            return i;
        }
    };
}
