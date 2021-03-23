#pragma once
#include <algorithm>
#include <vector>

namespace p1198
{
    class Solution
    {
      public:
        int smallestCommonElement(std::vector<std::vector<int>>& mat)
        {
            auto R = mat.size();
            auto C = mat.front().size();

            if (R == 0 || C == 0)
                return -1;

            for (auto col = 0; col < C; ++col)
            {
                auto curr = mat[0][col];
                bool found_everywhere = true;
                for (auto row = 1; row < R; ++row)
                {
                    found_everywhere = found_everywhere && std::binary_search(mat[row].begin(), mat[row].end(), curr);
                    if (!found_everywhere)
                        break;
                }
                if (found_everywhere)
                    return curr;
            }

            return -1;
        }
    };
}
