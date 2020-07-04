#pragma once
#include <array>
#include <string>
#include <vector>

namespace p212
{
    class Solution
    {
      public:
        std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words)
        {
            if (board.empty() || board[0].empty())
                return {};

            make_trie(words);

            for (size_t i = 0; i < board.size(); ++i)
                for (size_t j = 0; j < board.front().size(); ++j)
                {
                    std::string curr_prefix = "";
                    search(board, i, j, _wordsTrie, curr_prefix);
                }
            return _found;
        }

      private:
        std::vector<std::string> _found;

        struct TrieNode
        {
            bool IsWord = false;
            std::array<TrieNode*, 26> Children = {};
        };
        TrieNode* _wordsTrie = new TrieNode();

        void make_trie(const std::vector<std::string>& words)
        {
            for (const auto& w : words)
            {
                auto* currNode = _wordsTrie;

                for (size_t i = 0; i < w.size(); ++i)
                {
                    auto letter = w[i];

                    if (currNode->Children[size_t(letter) - 'a'] == nullptr)
                        currNode->Children[size_t(letter) - 'a'] = new TrieNode();

                    currNode = currNode->Children[size_t(letter) - 'a'];
                    if (i == w.size() - 1)
                        currNode->IsWord = true;
                }
            }
        }

        void search(std::vector<std::vector<char>>& board, size_t i, size_t j, TrieNode* curr_node, std::string& curr_prefix)
        {
            if (board[i][j] == '.')
                return;

            char current_letter = board[i][j];
            auto* next_node = curr_node->Children[size_t(current_letter) - 'a'];
            if (nullptr == next_node)
                return;

            board[i][j] = '.';
            curr_prefix.push_back(current_letter);

            if (next_node->IsWord)
            {
                _found.push_back(curr_prefix);
                next_node->IsWord = false;
            }

            if (i > 0)
                search(board, i - 1, j, next_node, curr_prefix);
            if (i < board.size() - 1)
                search(board, i + 1, j, next_node, curr_prefix);
            if (j > 0)
                search(board, i, j - 1, next_node, curr_prefix);
            if (j < board.front().size() - 1)
                search(board, i, j + 1, next_node, curr_prefix);

            board[i][j] = current_letter;
            curr_prefix.pop_back();
        }
    };
}
