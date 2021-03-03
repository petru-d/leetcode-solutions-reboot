#pragma once
#include <array>
#include <string>
#include <vector>
namespace p784
{
    class Solution
    {
      public:
        std::vector<std::string> letterCasePermutation(std::string S)
        {
            std::array<size_t, 12> letter_indices = {};

            auto is_letter = [](const char c) { return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'); };

            auto p2 = [](size_t exp) {
                auto p2_impl = [](size_t exp, auto& p2_ref) mutable {
                    if (exp <= 1)
                        return exp + 1;

                    if (exp % 2 == 1)
                        return 2 * p2_ref(exp - 1, p2_ref);

                    auto r = p2_ref(exp / 2, p2_ref);
                    return r * r;
                };

                return p2_impl(exp, p2_impl);
            };

            size_t bits = 0;
            for (size_t i = 0; i < S.size(); ++i)
                if (is_letter(S[i]))
                    letter_indices[bits++] = i;

            auto max = p2(bits);
            std::vector<std::string> result(max, S);
            for (size_t i = 0; i < max; ++i)
            {
                for (size_t b = 0; b < bits; ++b)
                {
                    auto letter_index = letter_indices[b];
                    auto& letter = result[i][letter_index];
                    letter = (i & (1 << b)) ? std::toupper(letter) : std::tolower(letter);
                }
            }

            return result;
        }
    };
}
