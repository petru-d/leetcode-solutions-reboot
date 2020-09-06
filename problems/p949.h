#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p949
{
    class Solution
    {
      public:
        std::string largestTimeFromDigits(std::vector<int>& A)
        {
            std::vector<std::vector<int>> candidates;

            std::sort(A.begin(), A.end());
            do
            {
                if (valid_time(A))
                    candidates.push_back(A);
            } while (std::next_permutation(A.begin(), A.end()));

            if (candidates.empty())
                return "";

            const auto& c = *std::max_element(candidates.begin(), candidates.end());

            return std::to_string(c[0]) + std::to_string(c[1]) + ":" + std::to_string(c[2]) + std::to_string(c[3]);
        }

      private:
        bool valid_time(const std::vector<int>& A)
        {
            if (A[0] > 2)
                return false;

            if (A[0] == 2 && A[1] > 3)
                return false;

            if (A[2] > 5)
                return false;

            return true;
        }
    };
}
