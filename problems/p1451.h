#pragma once
#include <sstream>
#include <string>
#include <vector>

namespace p1451
{
    class Solution
    {
      public:
        std::string arrangeWords(std::string text)
        {
            if (text.empty())
                return "";

            text[0] += 'a' - 'A';

            std::vector<std::string> words;
            std::istringstream is(text);
            std::string w;
            while (is >> w)
                words.emplace_back(std::move(w));

            std::stable_sort(words.begin(), words.end(), [](const auto& l, const auto& r) { return l.size() < r.size(); });

            std::string result;
            result.reserve(text.size());

            result = words[0];
            for (size_t i = 1; i < words.size(); ++i)
            {
                result.append(1, ' ');
                result.append(std::move(words[i]));
            }

            result[0] -= 'a' - 'A';
            return result;
        }
    };
}
