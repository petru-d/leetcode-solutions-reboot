#pragma once
#include <array>
#include <string>

namespace p273
{
    class Solution
    {
      public:
        std::string numberToWords(int num)
        {
            if (num == 0)
                return "Zero";

            std::array<std::string, 10> digits = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
            std::array<std::string, 10> teens = {"",        "Eleven",  "Twelve",    "Thirteen", "Fourteen",
                                                 "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            std::array<std::string, 10> tens = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
                                                "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

            std::string h = "Hundred";
            std::string t = "Thousand";
            std::string m = "Million";
            std::string b = "Billion";

            auto toWordsTill1000 = [&](int num) {
                int n_h = num / 100;
                int n_t = (num / 10) % 10;
                int n_u = num % 10;

                std::vector<std::string> result;

                if (n_h > 0)
                {
                    result.push_back(digits[n_h]);
                    result.push_back(h);
                }

                if (n_t >= 2)
                {
                    result.push_back(tens[n_t]);
                    if (n_u > 0)
                        result.push_back(digits[n_u]);
                }
                else if (n_t == 1)
                {
                    if (n_u > 0)
                        result.push_back(teens[n_u]);
                    else
                        result.push_back(tens[n_t]);
                }
                else
                {
                    if (n_u > 0)
                        result.push_back(digits[n_u]);
                }

                return result;
            };

            auto get_suffix = [&](size_t dist) {
                if (0 == dist)
                    return std::string{};
                if (1 == dist)
                    return t;
                if (2 == dist)
                    return m;
                if (3 == dist)
                    return b;

                return std::string("?");
            };

            auto add_spaces = [](std::vector<std::string>&& n) {
                std::string result = std::move(n[0]);
                for (size_t i = 1; i < n.size(); ++i)
                {
                    result.append(1, ' ');
                    result += std::move(n[i]);
                }
                return result;
            };

            std::vector<int> split_thousands;
            while (num > 0)
            {
                split_thousands.push_back(num % 1000);
                num = num / 1000;
            }
            std::reverse(split_thousands.begin(), split_thousands.end());

            std::vector<std::string> tokens;
            for (size_t i = 0; i < split_thousands.size(); ++i)
            {
                auto w1000 = toWordsTill1000(split_thousands[i]);
                for (auto&& w : w1000)
                    tokens.push_back(std::move(w));
                if (!w1000.empty())
                {
                    auto suff = get_suffix(split_thousands.size() - i - 1);
                    if (!suff.empty())
                        tokens.push_back(std::move(suff));
                }
            }

            return add_spaces(std::move(tokens));
        }
    };
}
