#pragma once
#include <vector>

namespace p54
{
    class Solution
    {
      public:
        std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
        {
            if (matrix.empty() || matrix.front().empty())
                return {};

            // separate into "concentric" rectangles - like an onion
            // we have min(R, C) / 2 + mic(R, C) % 2 slices
            auto R = matrix.size();
            auto C = matrix.front().size();

            auto slices = std::min(R, C) / 2 + std::min(R, C) % 2;

            // slice i looks like this:
            //      (i, i)        >     (i, C - i - 1)
            //        ^                        v
            //  (R - i - 1, i)    <   (R - i - 1, C - i - 1)

            std::vector<int> result;
            result.reserve(R * C);
            for (auto i = 0; i < slices; ++i)
            {
                // take the first line of the slice completely (including ends)
                for (int j = i; j <= C - i - 1; ++j)
                    result.push_back(matrix[i][j]);

                // edge case - current slice is only one line - don't double back to write the same line again
                if (i == R - i - 1)
                    break;

                // take the right column of the slice open (excluding ends)
                for (int j = i + 1; j <= R - i - 2; ++j)
                    result.push_back(matrix[j][C - i - 1]);

                // take the second line of the slice completely (including ends)
                for (int j = C - i - 1; j >= i; --j)
                    result.push_back(matrix[R - i - 1][j]);

                // edge case - current slice is only one column - don't double back to write the same column again
                if (i == C - i - 1)
                    break;

                // take the left column of the slice open (excluding ends)
                for (int j = R - i - 2; j >= i + 1; --j)
                    result.push_back(matrix[j][i]);
            }

            return result;
        }
    };
}
