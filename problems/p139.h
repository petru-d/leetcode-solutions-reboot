#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace p139
{
    class Solution
    {
      public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict)
        {
            return canBreak(s, 0, wordDict);
        }

      private:
        bool canBreak(const std::string& s, size_t start, const std::vector<std::string>& wordDict)
        {
            if (start >= s.size())
                return true;

            auto pos = _partialSolutions.find(start);
            if (pos != _partialSolutions.end())
                return pos->second;

            bool result = false;

            std::string_view v = s;
            for (const auto& word : wordDict)
            {
                if (word == v.substr(start, word.size()))
                    result = canBreak(s, start + word.size(), wordDict);
                if (result)
                    break;
            }

            _partialSolutions[start] = result;
            return result;
        }
        std::unordered_map<size_t, bool> _partialSolutions;
    };
}
