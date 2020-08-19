#pragma once
#include <sstream>
#include <string>

namespace p824
{
    class Solution
    {
      public:
        std::string toGoatLatin(std::string S)
        {
            std::string result;

            std::istringstream ss(S);

            std::string currWord;
            size_t i = 1;
            while (ss >> currWord)
            {
                result.append(goatify(currWord, i));
                result.append(1, ' ');
                ++i;
            }
            result.pop_back();

            return result;
        }

      private:
        std::string goatify(const std::string& word, size_t index)
        {
            auto isVowel = [](const char c) {
                return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' ||
                       c == 'u';
            };

            std::string result;

            if (isVowel(word.front()))
            {
                result = word + "ma";
            }
            else
            {
                result = word.substr(1) + std::string(1, word.front()) + "ma";
            }

            result.append(index, 'a');
            return result;
        }
    };
}
