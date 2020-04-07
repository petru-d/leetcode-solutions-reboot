#pragma once
#include <array>
#include <string>
#include <unordered_map>
#include <vector>

// already have a solution for this one in the previous repo, but doing it again, hopefully better

namespace p49
{
    class Solution
    {
      public:
        std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
        {
            std::vector<std::vector<std::string>> result;
            size_t count = std::size_t(-1);

            // to what element in result corresponds a certain category.
            std::unordered_map<std::string, size_t> data;

            for (auto& s : strs)
            {
                std::string sig = s;
                std::sort(sig.begin(), sig.end());

                auto pos = data.find(sig);
                if (pos == data.end())
                {
                    // new anagram category
                    result.push_back({});
                    result.back() = std::vector<std::string>(1, std::move(s));
                    data[std::move(sig)] = result.size() - 1;
                }
                else
                {
                    result[pos->second].emplace_back(std::move(s));
                }
            }

            return result;
        }
    };

}