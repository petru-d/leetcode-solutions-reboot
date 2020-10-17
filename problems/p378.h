#pragma once
#include <queue>
#include <vector>

namespace p378
{
    class Solution
    {
      public:
        int kthSmallest(std::vector<std::vector<int>>& matrix, int k)
        {
            size_t N = matrix.size();

            std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));

            auto gt_by_index = [&](const std::pair<size_t, size_t>& left, const std::pair<size_t, size_t>& right) {
                return matrix[left.first][left.second] > matrix[right.first][right.second];
            };

            std::priority_queue<std::pair<size_t, size_t>, std::vector<std::pair<size_t, size_t>>, decltype(gt_by_index)> queue(
                gt_by_index);

            queue.push({0, 0});

            for (int i = 1;; ++i)
            {
                auto curr = queue.top();
                if (i == k)
                    return matrix[curr.first][curr.second];

                queue.pop();

                size_t x = curr.first;
                size_t y = curr.second;

                visited[x][y] = true;

                // possible candidates for queue are down and left

                // check left
                if (y < N - 1)
                {
                    if (x == 0 || visited[x - 1][y + 1])
                        queue.push({x, y + 1});
                }

                // check down
                if (x < N - 1)
                {
                    if (y == 0 || visited[x + 1][y - 1])
                        queue.push({x + 1, y});
                }
            }

            return -1;
        }
    };
}
