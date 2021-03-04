#pragma once
#include <vector>

namespace p413
{
    class Solution
    {
      public:
        int numberOfArithmeticSlices(std::vector<int>& A)
        {
            auto AA = A.size();
            if (AA < 3)
                return 0;

            auto add_res = [](size_t span) { return int((span - 2) * (span - 1) / 2); };

            int res = 0;
            size_t curr = 1;
            while (curr < AA)
            {
                // expand sequence starting at curr - 1
                auto end = curr + 1;
                auto delta = A[curr] - A[curr - 1];
                while (end < AA && A[end] - A[end - 1] == delta)
                    ++end;

                if (end - curr >= 2)
                    res += add_res(end - curr + 1);

                curr = end;
            }

            return res;
        }
    };
}
