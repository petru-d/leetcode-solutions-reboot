#pragma once
#include <vector>

namespace p1074
{
    class Solution2
    {
      public:
        int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target)
        {
            auto R = matrix.size();
            auto C = matrix.front().size();

            std::vector<std::vector<int>> sums(R, std::vector<int>(C, 0));

            for (size_t i = 0; i < R; ++i)
            {
                int curr_line = 0;
                for (size_t j = 0; j < C; ++j)
                {
                    sums[i][j] = curr_line + matrix[i][j] + (i > 0 ? sums[i - 1][j] : 0);
                    curr_line += matrix[i][j];
                }
            }

            int result = 0;
            for (size_t i1 = 0; i1 < R; ++i1)
                for (size_t j1 = 0; j1 < C; ++j1)
                    for (size_t i2 = i1; i2 < R; ++i2)
                        for (size_t j2 = j1; j2 < C; ++j2)
                        {
                            // sum of matrix from (i1, j1) to (i2, j2) including
                            auto above = i1 > 0 ? sums[i1 - 1][j2] : 0;
                            auto left = j1 > 0 ? sums[i2][j1 - 1] : 0;
                            auto corner = (i1 > 0 && j1 > 0) ? sums[i1 - 1][j1 - 1] : 0;

                            auto i1j2_i2j2_sum = sums[i2][j2] - above - left + corner;
                            result += (i1j2_i2j2_sum == target);
                        }

            return result;
        }
    };

    class Solution
    {
      public:
        int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target)
        {
            auto R = matrix.size();
            auto C = matrix.front().size();

            std::vector<std::vector<int>> sums(R, std::vector<int>(C, 0));

            for (size_t i = 0; i < R; ++i)
            {
                int curr_line = 0;
                for (size_t j = 0; j < C; ++j)
                {
                    sums[i][j] = curr_line + matrix[i][j] + (i > 0 ? sums[i - 1][j] : 0);
                    curr_line += matrix[i][j];
                }
            }

            auto get_sum_i1j1_i2j2 = [&](size_t i1, size_t j1, size_t i2, size_t j2) {
                auto above = i1 > 0 ? sums[i1 - 1][j2] : 0;
                auto left = j1 > 0 ? sums[i2][j1 - 1] : 0;
                auto corner = (i1 > 0 && j1 > 0) ? sums[i1 - 1][j1 - 1] : 0;

                auto result = sums[i2][j2] - above - left + corner;
                return result;
            };

            size_t result = 0;
            for (size_t r1 = 0; r1 < R; ++r1)
                for (size_t r2 = r1; r2 < R; ++r2)
                {
                    std::unordered_map<size_t, size_t> sums;
                    sums[0] = 1;
                    int total_sum = 0;
                    for (size_t col = 0; col < C; ++col)
                    {
                        total_sum += get_sum_i1j1_i2j2(r1, col, r2, col);
                        // cout << "TS = " << total_sum << endl;

                        auto pos = sums.find(total_sum - target);
                        if (pos != sums.end())
                        {
                            result += pos->second;
                        }
                        ++sums[total_sum];
                    }
                }

            return int(result);
        }
    };

}
