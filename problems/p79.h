#pragma once

#include <string>
#include <vector>

namespace p79
{
    class Solution
    {
      public:
        bool exist(std::vector<std::vector<char>>& board, std::string word)
        {
            if (board.empty())
                return false;

            for (size_t i = 0; i < board.size(); ++i)
                for (size_t j = 0; j < board[0].size(); ++j)
                {
                    if (exist(board, i, j, word, 0))
                        return true;
                }

            return false;
        }

      private:
        bool exist(std::vector<std::vector<char>>& board, size_t i, size_t j, const std::string& word, size_t pos)
        {
            if (board[i][j] != word[pos])
                return false;

            if (pos == word.size() - 1)
                return true;

            auto c = board[i][j];
            board[i][j] = '.';

            bool res = false;
            if (i > 0 && exist(board, i - 1, j, word, pos + 1))
                res = true;
            if (!res && j > 0 && exist(board, i, j - 1, word, pos + 1))
                res = true;
            if (!res && i < board.size() - 1 && exist(board, i + 1, j, word, pos + 1))
                res = true;
            if (!res && j < board[0].size() - 1 && exist(board, i, j + 1, word, pos + 1))
                res = true;

            board[i][j] = c;
            return res;
        }
    };
}
