#pragma once
#include <array>
#include <string>
#include <unordered_set>
#include <vector>

namespace p1032
{
    class StreamChecker
    {
      public:
        StreamChecker(std::vector<std::string>& words)
        {
            for (const auto& w : words)
            {
                auto* curr = _trie;
                for (const auto l : w)
                {
                    auto* child = curr->Children[size_t(l) - 'a'];
                    if (nullptr == child)
                        curr->Children[size_t(l) - 'a'] = new TrieNode();
                    curr = curr->Children[size_t(l) - 'a'];
                }
                curr->Word = true;
            }
        }

        bool query(char letter)
        {
            size_t l = size_t(letter) - 'a';

            bool res = false;

            std::vector<TrieNode*> newActive;
            newActive.reserve(_active.size());
            if (_trie->Children[l] != nullptr)
            {
                newActive.push_back(_trie->Children[l]);
                res = _trie->Children[l]->Word;
            }

            for (const auto* a : _active)
            {
                if (a->Children[l] != nullptr)
                {
                    newActive.push_back(a->Children[l]);
                    res |= a->Children[l]->Word;
                }
            }
            _active = std::move(newActive);
            return res;
        }

      private:
        struct TrieNode
        {
            std::array<TrieNode*, 26> Children = {};
            bool Word = false;
        };
        TrieNode* _trie = new TrieNode();
        std::vector<TrieNode*> _active;
    };
}
