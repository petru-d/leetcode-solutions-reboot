#pragma once
#include <array>
#include <string>
namespace p208
{
    class Trie
    {
      public:
        /** Initialize your data structure here. */
        Trie()
        {
        }

        /** Inserts a word into the trie. */
        void insert(std::string word)
        {
            insert(_root, word, 0);
        }

        /** Returns if the word is in the trie. */
        bool search(std::string word)
        {
            return search(_root, word, 0, true);
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(std::string prefix)
        {
            return search(_root, prefix, 0, false);
        }

        struct TrieNode
        {
            std::array<TrieNode*, 26> Arrows = {};
            bool IsKey = false;
        };

        TrieNode* _root = new TrieNode();

        void insert(TrieNode* root, const std::string& word, size_t index)
        {
            if (index >= word.size())
            {
                root->IsKey = true;
                return;
            }

            size_t i = word[index] - size_t('a');

            if (root->Arrows[i] == nullptr)
                root->Arrows[i] = new TrieNode();
            insert(root->Arrows[i], word, index + 1);
        }

        bool search(TrieNode* root, const std::string& word, size_t index, bool must_be_key)
        {
            if (index >= word.size())
            {
                return must_be_key ? root->IsKey : true;
            }

            size_t i = word[index] - size_t('a');

            if (root->Arrows[i] == nullptr)
                return false;
            return search(root->Arrows[i], word, index + 1, must_be_key);
        }
    };
}