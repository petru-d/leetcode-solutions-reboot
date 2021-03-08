#pragma once
#include <array>
#include <string>
#include <vector>

namespace p820
{
    class Solution
    {
      public:
        struct TrieNode
        {
            size_t Depth = 0;
            bool IsLeaf = false;
            std::array<TrieNode*, 26> Children = {};
        };

        int minimumLengthEncoding(std::vector<std::string>& words)
        {
            int result = 0;
            TrieNode root;

            auto add_word = [&](const auto& w) {
                auto W = w.size();
                auto* curr = &root;
                bool leaf = false;
                for (size_t i = W; i > 0; --i)
                {
                    if (curr->IsLeaf)
                    {
                        curr->IsLeaf = false;
                        result -= curr->Depth + 1;
                    }
                    if (nullptr == curr->Children[w[i - 1] - 'a'])
                    {
                        curr->Children[w[i - 1] - 'a'] = new TrieNode{curr->Depth + 1, false, {}};
                        leaf = true;
                    }
                    curr = curr->Children[w[i - 1] - 'a'];
                    if (i == 1 && leaf)
                    {
                        curr->IsLeaf = true;
                        result += curr->Depth + 1;
                    }
                }
            };

            for (const auto& w : words)
            {
                add_word(w);
            }

            return result;
        }
    };

}
