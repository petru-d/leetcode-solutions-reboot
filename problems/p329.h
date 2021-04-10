#pragma once
#include <algorithm>
#include <vector>

namespace p329
{
    class Solution
    {
      public:
        int longestIncreasingPath(std::vector<std::vector<int>>& matrix)
        {
            if (matrix.empty() || matrix.front().empty())
                return 0;

            auto R = matrix.size();
            auto C = matrix.front().size();

            std::vector<std::vector<int>> lip(R, std::vector<int>(C, 0));

            int max = 0;
            for (size_t i = 0; i < R; ++i)
                for (size_t j = 0; j < C; ++j)
                    max = std::max(max, get_lip(matrix, i, j, lip));

            return max;
        }

        int get_lip(const std::vector<std::vector<int>>& matrix, size_t i, size_t j, std::vector<std::vector<int>>& lip)
        {
            if (lip[i][j] != 0)
                return lip[i][j];

            int east = (j > 0 && matrix[i][j] < matrix[i][j - 1]) ? get_lip(matrix, i, j - 1, lip) : 0;
            int west = (j < matrix.front().size() - 1 && matrix[i][j] < matrix[i][j + 1]) ? get_lip(matrix, i, j + 1, lip) : 0;
            int north = (i > 0 && matrix[i][j] < matrix[i - 1][j]) ? get_lip(matrix, i - 1, j, lip) : 0;
            int south = (i < matrix.size() - 1 && matrix[i][j] < matrix[i + 1][j]) ? get_lip(matrix, i + 1, j, lip) : 0;

            int lip_ij = 1 + std::max({east, west, north, south});

            return lip[i][j] = lip_ij;
        }
    };
}
