#pragma once
#include <array>
#include <string>
#include <vector>

namespace p423
{
    class Solution
    {
      public:
        std::string originalDigits(std::string s)
        {
            struct Signature
            {
                int Digit = -1;
                char Determinant = 0;
                std::array<size_t, 26> Sign = {};
            };

            auto make_signature = [](const std::string& word, int d, char det) {
                Signature res;
                res.Digit = d;
                res.Determinant = det;
                for (auto l : word)
                    ++res.Sign[l - 'a'];
                return res;
            };

            std::vector<std::vector<Signature>> priorities = {
                {make_signature("zero", 0, 'z'), make_signature("two", 2, 'w'), make_signature("four", 4, 'u'),
                 make_signature("six", 6, 'x')},
                {make_signature("three", 3, 'r'), make_signature("five", 5, 'f')},
                {make_signature("one", 1, 'o'), make_signature("seven", 7, 'v'), make_signature("eight", 8, 'g')},
                {make_signature("nine", 9, 'i')}};

            std::array<size_t, 26> counter = {};
            for (auto l : s)
                ++counter[l - 'a'];

            std::array<size_t, 10> result = {};
            for (const auto& curr_prio_class : priorities)
                for (const auto& signature : curr_prio_class)
                {
                    // the "determinant" dictates how many of this signature's digit we have to take
                    auto count_digit = counter[signature.Determinant - 'a'];
                    result[signature.Digit] = count_digit;

                    // the amount of characters we need to extract from the result
                    std::array<size_t, 26> extract = {};
                    std::transform(extract.begin(), extract.end(), signature.Sign.begin(), extract.begin(),
                                   [count_digit](size_t l, size_t r) { return r * count_digit; });

                    // extract the current signature from the result
                    std::transform(counter.begin(), counter.end(), extract.begin(), counter.begin(),
                                   [](size_t l, size_t r) { return l - r; });
                }

            std::string result_str;
            for (size_t i = 0; i < result.size(); ++i)
                if (result[i] != 0)
                    result_str.append(result[i], '0' + i);
            return result_str;
        }
    };
}
