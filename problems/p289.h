#pragma once
#include <vector>

namespace p289
{
    class Solution
    {
      public:
        void gameOfLife(std::vector<std::vector<int>>& board)
        {
            auto M = board.size();
            auto N = board.front().size();

            auto living = [&](size_t i, size_t j) {
                int live_neibs = 0;

                if (i > 0 && j > 0)
                    live_neibs += int(board[i - 1][j - 1] & 1);
                if (i > 0)
                    live_neibs += int(board[i - 1][j] & 1);
                if (i > 0 && j < N - 1)
                    live_neibs += int(board[i - 1][j + 1] & 1);
                if (j > 0)
                    live_neibs += int(board[i][j - 1] & 1);
                if (j < N - 1)
                    live_neibs += int(board[i][j + 1] & 1);
                if (i < M - 1 && j > 0)
                    live_neibs += int(board[i + 1][j - 1] & 1);
                if (i < M - 1)
                    live_neibs += int(board[i + 1][j] & 1);
                if (i < M - 1 && j < N - 1)
                    live_neibs += int(board[i + 1][j + 1] & 1);

                /*
                Any live cell with fewer than two live neighbors dies as if caused by under-population.
                Any live cell with two or three live neighbors lives on to the next generation.
                Any live cell with more than three live neighbors dies, as if by over-population.
                Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                */

                if (board[i][j] == 1)
                {
                    if (live_neibs < 2)
                        return 0;
                    if (live_neibs == 2 || live_neibs == 3)
                        return 1;
                    return 0;
                }
                else
                {
                    if (live_neibs == 3)
                        return 1;
                }

                return board[i][j];
            };

            auto encode = [&](int val, size_t i, size_t j) { board[i][j] |= (val << 8); };

            auto decode = [&](size_t i, size_t j) { board[i][j] = board[i][j] >> 8; };

            for (size_t i = 0; i < M; ++i)
                for (size_t j = 0; j < N; ++j)
                {
                    encode(living(i, j), i, j);
                }

            for (size_t i = 0; i < M; ++i)
                for (size_t j = 0; j < N; ++j)
                    decode(i, j);
        }
    };
}
