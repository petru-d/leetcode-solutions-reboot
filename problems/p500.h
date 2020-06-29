#pragma once
#include <algorithm>
#include <array>
#include <bitset>
#include <string>
#include <vector>

namespace p500
{
    class Solution
    {
      public:
        std::vector<std::string> findWords(std::vector<std::string>& words)
        {
            constexpr size_t span_len = 1 + 'z' - 'A';
            constexpr size_t up_to_low_diff = 'a' - 'A';

            std::array<std::string, 3> rows_letters = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};

            std::array<std::bitset<span_len>, 3> row_signatures = {};

            for (size_t i = 0; i < 3; ++i)
                for (auto c : rows_letters[i])
                {
                    row_signatures[i][c - 'A'] = true;
                    row_signatures[i][c + up_to_low_diff - 'A'] = true;
                }

            std::vector<std::string> result;
            for (auto& w : words)
            {
                bool can_form = std::any_of(row_signatures.begin(), row_signatures.end(), [&w](const std::bitset<span_len>& row) {
                    return std::all_of(w.begin(), w.end(), [&row](char c) { return row[c - 'A']; });
                });

                if (can_form)
                    result.emplace_back(std::move(w));
            }

            return result;
        }
    };
}
