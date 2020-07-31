#pragma once

#include <array>
#include <bitset>
#include <map>
#include <string>
#include <vector>

namespace p140
{
    class Solution
    {
      public:
        std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict)
        {
            // std::bitset<26> letters_in_dict;
            // for (const auto& word : wordDict)
            //    for (const auto letter : word)
            //        letters_in_dict[size_t(letter) - 'a'] = true;

            // for (const auto letter : s)
            //    if (!letters_in_dict[size_t(letter) - 'a'])
            //        return {};

            _wordDict = std::move(wordDict);
            make_trie();

            _raw_solutions = gather_solutions(s, 0);

            return inflate_solutions();
        }

      private:
        struct TrieNode
        {
            std::array<TrieNode*, 26> Children = {};
            size_t IndexInDict = size_t(-1);
        };

        void make_trie()
        {
            for (auto it = _wordDict.cbegin(); it != _wordDict.cend(); ++it)
            {
                const auto& word = *it;
                auto* curr_node = _dict;
                for (const auto& letter : word)
                {
                    if (curr_node->Children[size_t(letter) - 'a'] == nullptr)
                        curr_node->Children[size_t(letter) - 'a'] = new TrieNode();
                    curr_node = curr_node->Children[size_t(letter) - 'a'];
                }

                curr_node->IndexInDict = std::distance(_wordDict.cbegin(), it);
            }
        }

        std::vector<size_t> get_matching_prefixes(const std::string& s, size_t start)
        {
            std::vector<size_t> matching_prefixes;

            auto* curr_node = _dict;

            for (size_t i = start; i < s.size(); ++i)
            {
                const auto letter = s[i];

                if (curr_node->Children[size_t(letter) - 'a'] == nullptr)
                    break;

                curr_node = curr_node->Children[size_t(letter) - 'a'];

                if (curr_node->IndexInDict != size_t(-1))
                    matching_prefixes.push_back(curr_node->IndexInDict);
            }

            return matching_prefixes;
        }

        std::vector<std::vector<size_t>> gather_solutions(const std::string& s, size_t start)
        {
            if (start >= s.size())
            {
                return {{}};
            }

            auto partial_solution_it = _partial_solutions.find(s.substr(start));
            if (partial_solution_it != _partial_solutions.end())
                return partial_solution_it->second;

            std::vector<std::vector<size_t>> partial_solution_s;

            const auto matchin_preffixes = get_matching_prefixes(s, start);
            for (const auto preffix_index : matchin_preffixes)
            {
                auto solutions_rest = gather_solutions(s, start + _wordDict[preffix_index].size());

                for (auto& sol_rest : solutions_rest)
                {
                    sol_rest.insert(sol_rest.begin(), preffix_index);
                    partial_solution_s.push_back(std::move(sol_rest));
                }
            }

            return _partial_solutions[s.substr(start)] = partial_solution_s;
        }

        std::vector<std::string> inflate_solutions()
        {
            std::vector<std::string> result;

            for (const auto& raw : _raw_solutions)
            {
                std::string curr_inflated = _wordDict[raw[0]];
                for (auto it = std::next(raw.cbegin()); it != raw.cend(); ++it)
                {
                    curr_inflated.append(1, ' ');
                    curr_inflated.append(_wordDict[*it]);
                }
                result.push_back(std::move(curr_inflated));
            }

            return result;
        }

        std::vector<std::string> _wordDict;
        TrieNode* _dict = new TrieNode();

        std::vector<std::vector<size_t>> _raw_solutions;

        std::map<std::string, std::vector<std::vector<size_t>>> _partial_solutions;
    };
}
