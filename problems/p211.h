#pragma once
#include <array>
#include <string>
#include <vector>

namespace p211
{

    class WordDictionary
    {
      public:
        /** Initialize your data structure here. */
        WordDictionary()
        {
        }

        /** Adds a word into the data structure. */
        void addWord(std::string word)
        {
            auto* curr = _trie;
            std::vector<TrieNode*> path = {curr};
            for (const auto l : word)
            {
                if (curr->Children[l - 'a'] == nullptr)
                {
                    curr->Children[l - 'a'] = new TrieNode();
                }
                curr = curr->Children[l - 'a'];
                path.push_back(curr);
            }
            curr->IsWord = true;

            for (auto it = std::next(path.rbegin()); it != path.rend(); ++it)
            {
                (*it)->MaxDepthBelow = std::max((*it)->MaxDepthBelow, uint16_t(1 + (*std::prev(it))->MaxDepthBelow));
            }
        }

        /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
         */
        bool search(std::string word)
        {
            return search(word, 0, _trie);
        }

      private:
        struct TrieNode
        {
            std::array<TrieNode*, 26> Children = {};
            uint16_t MaxDepthBelow = 0;
            bool IsWord = false;
        };
        TrieNode* _trie = new TrieNode();

        bool search(const std::string& word, const size_t i, TrieNode* curr)
        {
            if (i >= word.size())
                return curr && curr->IsWord;

            if (curr == nullptr || curr->MaxDepthBelow < word.size() - i)
                return false;

            const auto l = word[i];

            if (l != '.')
                return search(word, i + 1, curr->Children[l - 'a']);

            for (auto* c : curr->Children)
                if (search(word, i + 1, c))
                    return true;

            return false;
        }
    };
}
