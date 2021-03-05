#pragma once
#include <vector>

namespace p240
{
    class Solution
    {
      public:
        bool searchMatrix_per_row(std::vector<std::vector<int>>& matrix, int target)
        {
            for (size_t l = 0; l < matrix.size(); ++l)
            {
                auto pos = std::lower_bound(matrix[l].begin(), matrix[l].end(), target);
                if (pos != matrix[l].end() && *pos == target)
                    return true;
            }
            return false;
        }

        size_t L = -1;
        size_t C = -1;

        bool searchMatrix_mine(std::vector<std::vector<int>>& matrix, int target)
        {
            L = matrix.size();
            C = matrix.front().size();
            return search(matrix, target, 0, 0, L, C);
        }

        // divide et impera
        // 0 | 1
        // -----
        // 2 | 3
        bool search(const std::vector<std::vector<int>>& matrix, int target, size_t Ax, size_t Ay, size_t Bx, size_t By)
        {
            if ((Ax > Bx || By < Ay || Ax >= L || Ay >= C) ||
                (target < matrix[Ax][Ay] || target > matrix[Ax == Bx ? Ax : Bx - 1][Ay == By ? Ay : By - 1]))
            {
                return false;
            }

            auto Px = (Ax + Bx) / 2;
            auto Py = (Ay + By) / 2;

            if (matrix[Px][Py] == target)
                return true;

            if (target < matrix[Px][Py])
                return search(matrix, target, Ax, Ay, Px, Py) || // 0
                       search(matrix, target, Ax, Py, Px, By) || // 1
                       search(matrix, target, Px, Ay, Bx, Py);   // 2

            return search(matrix, target, Ax, Py, Px, By) || // 1
                   search(matrix, target, Px, Ay, Bx, Py) || // 2
                   search(matrix, target, Px, Py, Bx, By);   // 3
        }

        // from top-right (leetcode solution):
        // if target < mat[x][y] -> column y is not a thing - continue with x, y - 1
        // else row x is not a thin - continue with x + 1, y
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
        {
            L = matrix.size();
            C = matrix.front().size();

            int x = 0;
            int y = C - 1;
            while (x < L && y >= 0)
            {
                if (matrix[x][y] == target)
                    return true;
                if (target < matrix[x][y])
                    --y;
                else
                    ++x;
            }
            return false;
        }
    };
}
