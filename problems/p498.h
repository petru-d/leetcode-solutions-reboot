#pragma once
#include <vector>

namespace p498
{
    class Solution
    {
      public:
        std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& matrix)
        {
            using Coord = std::pair<int, int>;

            if (matrix.empty() || matrix.front().empty())
                return {};

            auto M = int(matrix.size());
            auto N = int(matrix.front().size());

            std::vector<int> result;
            result.reserve(M * N);

            auto adv_up = [&](std::pair<int, int> p) {
                if (p == Coord{-1, -1})
                    return Coord{-1, -1};

                if (p.second == 0)
                {
                    if (p.first < M - 1)
                        return Coord{p.first + 1, 0};
                    if (N > 1)
                        return Coord{M - 1, 1};
                    return Coord{-1, -1};
                }

                if (p.second < N - 1)
                    return Coord{M - 1, p.second + 1};
                return Coord{-1, -1};
            };

            auto adv_down = [&](std::pair<int, int> p) {
                if (p == Coord{-1, -1})
                    return Coord{-1, -1};

                if (p.first == 0)
                {
                    if (p.second < N - 1)
                        return Coord{0, p.second + 1};
                    if (M > 1)
                        return Coord{1, N - 1};
                    return Coord{-1, -1};
                }

                if (p.first < M - 1)
                    return Coord{p.first + 1, N - 1};
                return Coord{-1, -1};
            };

            auto diag = [&](bool up, std::pair<int, int> p) {
                while (0 <= p.first && p.first < M && 0 <= p.second && p.second < N)
                {
                    result.push_back(matrix[size_t(p.first)][size_t(p.second)]);
                    if (up)
                    {
                        --p.first;
                        ++p.second;
                    }
                    else
                    {
                        ++p.first;
                        --p.second;
                    }
                }
            };

            Coord curr_up = Coord{0, 0};
            Coord curr_down = N > 1 ? Coord{0, 1} : M > 1 ? Coord{1, 0} : Coord{-1, -1};
            bool up = true;

            while ((up && curr_up != Coord{-1, -1}) || (!up && curr_down != Coord{-1, -1}))
            {
                if (up && curr_up != Coord{-1, -1})
                {
                    diag(up, curr_up);
                    curr_up = adv_up(curr_up);
                    curr_up = adv_up(curr_up);
                }
                if (!up && curr_down != Coord{-1, -1})
                {
                    diag(up, curr_down);
                    curr_down = adv_down(curr_down);
                    curr_down = adv_down(curr_down);
                }
                up = !up;
            }

            return result;
        }
    };
}
