#pragma once
#include <algorithm>
#include <string>

namespace p520
{
    class Solution
    {
      public:
        bool detectCapitalUse(std::string word)
        {
            if (word.empty())
                return true;

            auto is_capital = [](const char l) { return 'A' <= l && l <= 'Z'; };

            if (!is_capital(word.front()))
            {
                auto pos_next_capital = std::find_if(std::next(word.begin()), word.end(), is_capital);
                return pos_next_capital == word.end();
            }

            if (word.size() == 1)
                return true;

            bool second_capital = is_capital(*std::next(word.begin()));
            if (!second_capital)
            {
                auto pos_next_next_capital = std::find_if(std::next(std::next(word.begin())), word.end(), is_capital);
                return pos_next_next_capital == word.end();
            }

            return std::all_of(std::next(std::next(word.begin())), word.end(), is_capital);
        }
    };
}
