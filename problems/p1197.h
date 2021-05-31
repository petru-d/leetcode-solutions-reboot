#pragma once
#include <vector>

namespace p1197
{
    class Solution2
    {
      public:
        int minKnightMoves(int x, int y)
        {
            if (x == 0 && y == 0)
                return 0;

            x = std::abs(x);
            y = std::abs(y);

            size_t H = x == 0 ? 5 : size_t(x) + 4;
            size_t W = y == 0 ? 5 : size_t(y) + 4;

            auto get_neibs = [&H, &W](const std::pair<size_t, size_t>& pos) {
                std::vector<std::pair<size_t, size_t>> n;
                n.reserve(8);

                if (pos.first + 1 < H && pos.second + 2 < W)
                    n.push_back({pos.first + 1, pos.second + 2});
                if (pos.first + 2 < H && pos.second + 1 < W)
                    n.push_back({pos.first + 2, pos.second + 1});
                if (pos.first > 0 && pos.second + 2 < W)
                    n.push_back({pos.first - 1, pos.second + 2});
                if (pos.first > 1 && pos.second + 1 < W)
                    n.push_back({pos.first - 2, pos.second + 1});
                if (pos.first + 1 < H && pos.second > 1)
                    n.push_back({pos.first + 1, pos.second - 2});
                if (pos.first + 2 < H && pos.second > 0)
                    n.push_back({pos.first + 2, pos.second - 1});
                if (pos.first > 0 && pos.second > 1)
                    n.push_back({pos.first - 1, pos.second - 2});
                if (pos.first > 1 && pos.second > 0)
                    n.push_back({pos.first - 2, pos.second - 1});

                return n;
            };

            // moves[i][j] contains the number of moves needed to reach [i - 2][j - 2]
            // -1 if not already calculated;
            std::vector<std::vector<int>> moves(H, std::vector<int>(W, -1));

            moves[2][2] = 0;

            std::vector<std::pair<size_t, size_t>> q = {{2, 2}};

            while (!q.empty())
            {
                std::vector<std::pair<size_t, size_t>> new_q;

                for (const auto& pos : q)
                {
                    auto neibs = get_neibs(pos);
                    for (const auto& n : neibs)
                    {
                        if (moves[n.first][n.second] != -1)
                            continue;

                        moves[n.first][n.second] = moves[pos.first][pos.second] + 1;
                        if (n.first == x + 2 && n.second == y + 2)
                            return moves[n.first][n.second];

                        new_q.push_back(n);
                    }
                }

                std::swap(q, new_q);
            }

            assert(false);
            return -1;
        }
    };

    class Solution
    {
      public:
        int minKnightMoves(int x, int y)
        {
            if (x == 0 && y == 0)
                return 0;

            if (x < 0 || y < 0)
                return minKnightMoves(abs(x), abs(y));

            if (y > x)
                return minKnightMoves(y, x);

            // we are far - jump towards the origin
            if (x + y >= 8)
                return 1 + minKnightMoves(x - 2, y - 1);

            Solution2 s2;
            return s2.minKnightMoves(x, y);
        }
    };
}
