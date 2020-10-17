#pragma once
#include <array>
#include <optional>
#include <string>

namespace p859
{
    class Solution
    {
      public:
        bool buddyStrings(std::string A, std::string B)
        {
            size_t N = A.size();
            if (B.size() != N)
                return false;

            std::optional<size_t> diff1_index;
            std::optional<size_t> diff2_index;

            std::array<size_t, 26> counter{};

            for (size_t i = 0; i < N; ++i)
            {
                if (A[i] != B[i])
                {
                    if (!diff1_index)
                        diff1_index = i;
                    else if (!diff2_index)
                        diff2_index = i;
                    else
                        return false;
                }

                ++counter[A[i] - 'a'];
            }

            if (!diff1_index)
                return std::any_of(counter.begin(), counter.end(), [](size_t c) { return c >= 2; });

            if (!diff2_index)
                return false;

            return A[diff1_index.value()] == B[diff2_index.value()] && A[diff2_index.value()] == B[diff1_index.value()];
        }
    };
}
