#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

namespace p986
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>>& A, std::vector<std::vector<int>>& B)
        {
            std::vector<std::vector<int>> result;

            size_t curr_b = 0;
            size_t curr_a = 0;

            while (curr_a < A.size() && curr_b < B.size())
            {
                auto intersection = intersect(A[curr_a], B[curr_b]);
                if (!intersection.empty())
                    result.push_back(intersection);

                bool advance_a = (A[curr_a][1] <= B[curr_b][1]);
                bool advance_b = (A[curr_a][1] >= B[curr_b][1]);

                if (advance_a)
                    ++curr_a;
                if (advance_b)
                    ++curr_b;
            }

            return result;
        }

      private:
        std::vector<int> intersect(const std::vector<int>& i1, const std::vector<int>& i2)
        {
            if (i1[0] > i2[1] || i1[1] < i2[0])
                return {};

            return {std::max(i1[0], i2[0]), std::min(i1[1], i2[1])};
        }
    };
}