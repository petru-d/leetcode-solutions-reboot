#pragma once
#include <array>
#include <string>
#include <vector>

namespace p17
{
    class Solution
    {
      public:
        std::vector<std::string> letterCombinations(std::string digits)
        {
            if (digits.empty())
                return {};

            std::vector<std::string> solution;
            std::string current;
            generate(digits, 0, current, solution);

            return solution;
        }

        void generate(const std::string& digits, size_t pos, std::string& current, std::vector<std::string>& solution)
        {
            if (pos >= digits.size())
            {
                solution.push_back(current);
                return;
            }

            for (auto letter : digit_letters[digits[pos] - '0'])
            {
                current.push_back(letter);
                generate(digits, pos + 1, current, solution);
                current.pop_back();
            }
        }

        std::array<std::string, 10> digit_letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    };
}
