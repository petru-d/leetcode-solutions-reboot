#pragma once
#include <vector>

namespace p63
{
    class Solution
    {
      public:
        int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid)
        {
            auto M = obstacleGrid.size();
            auto N = obstacleGrid.front().size();

            if (M == 0 || N == 0 || obstacleGrid[0][0] == 1)
                return 0;

            std::vector<size_t> unique_paths(N, 0);
            unique_paths[0] = 1;
            for (size_t col = 1; col < N; ++col)
                unique_paths[col] = (obstacleGrid[0][col] == 1) ? 0 : unique_paths[col - 1];

            std::vector<size_t> new_unique_paths(N, 0);
            for (size_t row = 1; row < M; ++row)
            {
                new_unique_paths[0] = (obstacleGrid[row][0] == 1) ? 0 : unique_paths[0];
                for (size_t col = 1; col < N; ++col)
                    new_unique_paths[col] = (obstacleGrid[row][col] == 1) ? 0 : new_unique_paths[col - 1] + unique_paths[col];

                std::swap(unique_paths, new_unique_paths);
            }

            return unique_paths.back();
        }
    };
}
