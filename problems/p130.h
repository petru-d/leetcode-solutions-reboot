#pragma once
#include <vector>

namespace p130
{
    class Solution
    {
      public:
        // replace 'O' with '*'
        void flood(size_t r, size_t c, std::vector<std::vector<char>>& board)
        {
            if (board[r][c] != 'O')
                return;

            board[r][c] = '*';

            if (r > 0)
                flood(r - 1, c, board);
            if (r < board.size() - 1)
                flood(r + 1, c, board);
            if (c > 0)
                flood(r, c - 1, board);
            if (c < board.front().size() - 1)
                flood(r, c + 1, board);
        }

        void solve(std::vector<std::vector<char>>& board)
        {
            if (board.empty())
                return;
            if (board.front().empty())
                return;

            for (size_t r = 0; r < board.size(); ++r)
            {
                if (board[r][0] == 'O')
                    flood(r, 0, board);
                if (board[r][board.front().size() - 1] == 'O')
                    flood(r, board.front().size() - 1, board);
            }

            for (size_t c = 0; c < board.front().size(); ++c)
            {
                if (board[0][c] == 'O')
                    flood(0, c, board);
                if (board[board.size() - 1][c] == 'O')
                    flood(board.size() - 1, c, board);
            }

            for (size_t r = 0; r < board.size(); ++r)
                for (size_t c = 0; c < board.front().size(); ++c)
                {
                    if (board[r][c] == 'O')
                        board[r][c] = 'X';
                    if (board[r][c] == '*')
                        board[r][c] = 'O';
                }
        }
    };
}
