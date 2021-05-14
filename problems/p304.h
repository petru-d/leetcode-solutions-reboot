#pragma once
#include <vector>

namespace p304
{
    class NumMatrix
    {
      public:
        NumMatrix(std::vector<std::vector<int>>& matrix)
        {
            R = matrix.size();
            C = matrix.front().size();

            sums = std::vector<std::vector<int>>(R, std::vector<int>(C, 0));

            // top-left corner
            sums[0][0] = matrix[0][0];

            // top line
            for (size_t c = 1; c < C; ++c)
                sums[0][c] = sums[0][c - 1] + matrix[0][c];

            // left column
            for (size_t r = 1; r < R; ++r)
                sums[r][0] = sums[r - 1][0] + matrix[r][0];

            // rest
            for (size_t r = 1; r < R; ++r)
                for (size_t c = 1; c < C; ++c)
                    sums[r][c] = sums[r - 1][c] + sums[r][c - 1] + matrix[r][c] - sums[r - 1][c - 1];
        }

        int sumRegion(int row1, int col1, int row2, int col2)
        {
            auto left = col1 > 0 ? sums[row2][col1 - 1] : 0;
            auto top = row1 > 0 ? sums[row1 - 1][col2] : 0;
            auto diag = row1 > 0 && col1 > 0 ? sums[row1 - 1][col1 - 1] : 0;
            auto all = sums[row2][col2];

            return all - left - top + diag;
        }

      private:
        size_t R = -1;
        size_t C = -1;
        // sums[i][j] is the sum of the region from 0,0 up to and including i j
        std::vector<std::vector<int>> sums;
    };
}
