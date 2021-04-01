#pragma once
#include <algorithm>
#include <array>
#include <queue>
#include <vector>

namespace p1133
{
    class Solution
    {
      public:
        int largestUniqueNumber(std::vector<int>& A)
        {
            auto N = A.size();
            if (N == 0)
                return -1;

            std::array<size_t, 1001> occurences = {};

            for (auto a : A)
                ++occurences[size_t(a)];

            auto pos = std::find(occurences.rbegin(), occurences.rend(), 1);
            return pos == occurences.rend() ? -1 : int(1000 - std::distance(occurences.rbegin(), pos));
        }
    };

    class Solution2
    {
      public:
        int largestUniqueNumber(std::vector<int>& A)
        {
            auto N = A.size();
            if (N == 0)
                return -1;

            std::make_heap(A.begin(), A.end());
            std::pop_heap(A.begin(), A.end());

            int prev = A.back();
            A.pop_back();

            while (!A.empty())
            {
                int curr = -1;
                bool found_prev = false;
                do
                {
                    std::pop_heap(A.begin(), A.end());
                    curr = A.back();
                    A.pop_back();
                    if (curr == prev)
                        found_prev = true;
                } while (!A.empty() && curr == prev);

                if (!found_prev)
                    return prev;

                if (A.empty())
                    return curr == prev ? -1 : curr;

                prev = curr;
            }
            return prev;
        }
    };
}
