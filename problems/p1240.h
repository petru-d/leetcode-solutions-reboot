#pragma once

#include <algorithm>
#include <vector>

namespace p1240
{
    class Solution
    {
      private:
        std::vector<std::vector<int>> best_solution_dp;
        std::vector<std::vector<bool>> have_best_solution;

        int best = std::numeric_limits<int>::max();

      public:
        int tilingRectangle(int n, int m)
        {
            run_dp(n, m);

            if (have_best_solution[n][m])
                return best_solution_dp[n][m];

            std::vector<int> skyline(m, 0);
            dfs(n, m, skyline, m * n, 0, n);
            return best;
        }

        void run_dp(int n, int m)
        {
            auto gcd = [](int n, int m) {
                while (m != 0)
                {
                    auto t = m;
                    m = n % m;
                    n = t;
                }
                return n;
            };

            best_solution_dp = std::vector<std::vector<int>>(size_t(n) + 1, std::vector<int>(size_t(m) + 1, 1));
            have_best_solution = std::vector<std::vector<bool>>(size_t(n) + 1, std::vector<bool>(size_t(m) + 1, false));

            // Yhis strategy works correctly for m, n <=4
            for (int i = 1; i <= std::min(n, 4); ++i)
                for (int j = 1; j <= m; ++j)
                    have_best_solution[i][j] = true;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= std::min(m, 4); ++j)
                    have_best_solution[i][j] = true;

            // A rectangle of 1 by X is tiled optimally with n squares
            for (int i = 1; i <= n; ++i)
                best_solution_dp[i][1] = i;
            for (int j = 1; j <= m; ++j)
                best_solution_dp[1][j] = j;

            // A rectangle of 2 by X is tiled optimally with X/2 squares for even X and X / 2 + 2 for odd.
            if (m >= 2)
                for (int i = 3; i <= n; ++i)
                    best_solution_dp[i][2] = (i % 2 == 0) ? (i / 2) : (i / 2 + 2);
            if (n >= 2)
                for (int j = 3; j <= m; ++j)
                    best_solution_dp[2][j] = (j % 2 == 0) ? (j / 2) : (j / 2 + 2);

            // Due to scaling, an optimal solution for aX by aY is optimal for X by Y.
            for (int i = 3; i <= n; ++i)
                for (int j = 3; j <= m; ++j)
                {
                    auto g = gcd(i, j);
                    if (g > 1)
                    {
                        best_solution_dp[i][j] = best_solution_dp[i / g][j / g];
                        have_best_solution[i][j] = have_best_solution[i / g][j / g];
                    }
                    else
                    {
                        best_solution_dp[i][j] = 1 + ((i < j) ? best_solution_dp[i][j - i] : best_solution_dp[i - j][j]);
                    }
                }
        }

        void dfs(int n, int m, std::vector<int>& skyline, int area_left, int used_count, int max_height)
        {
            if (area_left == 0)
            {
                best = std::min<int>(best, used_count);
                return;
            }

            // abandon search
            if (used_count >= best_solution_dp[n][m])
            {
                return;
            }

            int lowest_start = 0;
            int lowest_width = 0;

            for (int x = 0; x < skyline.size(); ++x)
            {
                if (skyline[x] < skyline[lowest_start])
                {
                    lowest_start = x;
                }
            }

            for (int index = lowest_start; index < skyline.size(); ++index)
            {
                if (skyline[index] == skyline[lowest_start])
                {
                    lowest_width++;
                }
                else
                {
                    break;
                }
            }

            for (int width = lowest_width; width > 0; --width)
            {
                if (skyline[lowest_start] + width <= max_height)
                {
                    for (int i = 0; i < width; ++i)
                    {
                        skyline[lowest_start + i] += width;
                    }
                    dfs(n, m, skyline, area_left - width * width, used_count + 1, max_height);
                    for (int i = 0; i < width; ++i)
                    {
                        skyline[lowest_start + i] -= width;
                    }
                }
            }
        }
    };
}
