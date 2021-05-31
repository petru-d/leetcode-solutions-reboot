#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p1268
{
    class Solution2
    {
      public:
        std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord)
        {
            auto add_to_trie = [&](const std::string& word, size_t index) {
                TrieNode* curr = &_trie;

                for (const auto l : word)
                {
                    if (curr->Children[l - 'a'] == nullptr)
                        curr->Children[l - 'a'] = new TrieNode();
                    curr = curr->Children[l - 'a'];
                    curr->Indexes.push_back(index);
                }
            };

            std::sort(products.begin(), products.end());
            auto P = products.size();
            for (size_t i = 0; i < P; ++i)
            {
                add_to_trie(products[i], i);
            }

            auto result = std::vector<std::vector<std::string>>(searchWord.size(), std::vector<std::string>{});

            auto* curr = &_trie;
            auto S = searchWord.size();
            for (size_t l = 0; l < S; ++l)
            {
                curr = curr->Children[searchWord[l] - 'a'];
                if (!curr)
                    break;
                for (size_t i = 0; i < 3; ++i)
                {
                    if (i >= curr->Indexes.size())
                        break;
                    result[l].push_back(products[curr->Indexes[i]]);
                }
            }

            return result;
        }

        struct TrieNode
        {
            std::array<TrieNode*, 26> Children = {};
            std::vector<size_t> Indexes;
        };
        TrieNode _trie;
    };

    class Solution
    {
      public:
        std::vector<std::vector<std::string>> suggestedProducts(std::vector<std::string>& products, std::string searchWord)
        {
            std::sort(products.begin(), products.end());

            auto result = std::vector<std::vector<std::string>>(searchWord.size(), std::vector<std::string>{});

            auto S = searchWord.size();
            for (size_t l = 0; l < S; ++l)
            {
                auto search_prefix = std::string_view(searchWord.data(), l + 1);

                auto pos = std::lower_bound(products.begin(), products.end(), search_prefix);

                bool added = false;
                int i = 0;
                while (i < 3 && pos != products.end() && 0 == pos->rfind(search_prefix, 0))
                {
                    result[l].push_back(*pos);
                    added = true;
                    ++i;
                    ++pos;
                }
                if (!added)
                    break;
            }

            return result;
        }
    };
}
