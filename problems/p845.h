#pragma once
#include <vector>

namespace p845
{
    class Solution
    {
      public:
        int longestMountain(std::vector<int>& A)
        {
            auto AA = A.size();
            if (AA < 3)
                return 0;

            enum class State
            {
                Ascending,
                Descending
            };

            size_t best_mountain = 0;

            State s = State::Ascending;
            size_t mountain_start = 0;
            while (mountain_start < AA - 1 && A[mountain_start] >= A[mountain_start + 1])
                ++mountain_start;

            for (size_t i = mountain_start + 1; i < AA; ++i)
            {
                if (A[i - 1] < A[i])
                {
                    if (s == State::Descending)
                    {
                        best_mountain = std::max(best_mountain, i - mountain_start);
                        mountain_start = i - 1;
                        s = State::Ascending;
                    }
                }
                else if (A[i - 1] > A[i])
                {
                    if (s == State::Ascending)
                        s = State::Descending;
                }
                else
                {
                    if (s == State::Descending)
                    {
                        best_mountain = std::max(best_mountain, i - mountain_start);
                    }

                    while (i < AA && A[i - 1] >= A[i])
                        ++i;
                    mountain_start = i - 1;
                    s = State::Ascending;
                }
            }

            if (s == State::Descending)
                best_mountain = std::max(best_mountain, AA - mountain_start);

            if (best_mountain < 3)
                best_mountain = 0;

            return int(best_mountain);
        }
    };
}
