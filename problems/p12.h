#pragma once
#include <string>

namespace p12
{
    class Solution
    {
      public:
        std::string intToRoman(int num)
        {
            int thousands = num / 1000;
            int hundreds = (num / 100) % 10;
            int tens = (num / 10) % 10;
            int units = num % 10;

            auto make_thousands = [](int thousands) { return std::string(size_t(thousands), 'M'); };
            auto make_number = [](int amount, char ten, char five, char one) {
                if (amount == 9)
                    return std::string(1, one).append(1, ten);
                if (amount >= 5)
                    return std::string(1, five).append(amount - 5, one);
                if (amount == 4)
                    return std::string(1, one).append(1, five);
                return std::string(size_t(amount), one);
            };

            auto result = make_thousands(thousands);
            result.append(make_number(hundreds, 'M', 'D', 'C'));
            result.append(make_number(tens, 'C', 'L', 'X'));
            result.append(make_number(units, 'X', 'V', 'I'));

            return result;
        }
    };
}
