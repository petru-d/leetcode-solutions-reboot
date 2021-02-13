#pragma once
#include <string>

namespace p1071
{
    class Solution
    {
      public:
        std::string gcdOfStrings(std::string str1, std::string str2)
        {
            size_t curr = 0;
            while (curr < str1.size() && curr < str2.size() && str1[curr] == str2[curr])
                ++curr;

            if (curr == 0)
                return "";

            // gcd is at most [0.. curr)

            auto divide = [&](size_t curr) {
                if (str1.size() % curr != 0 || str2.size() % curr != 0)
                    return false;

                auto d1 = str1.size() / curr;
                auto d2 = str2.size() / curr;

                for (size_t i = d1 - 1; i >= 1; --i)
                    for (size_t c = 0; c < curr; ++c)
                        if (str1[c] != str1[i * curr + c])
                            return false;
                for (size_t i = d2 - 1; i >= 1; --i)
                    for (size_t c = 0; c < curr; ++c)
                        if (str2[c] != str2[i * curr + c])
                            return false;

                return true;
            };

            size_t l = 1;
            size_t r = curr;

            for (size_t x = curr; x >= 1; --x)
            {
                if (divide(x))
                    return str1.substr(0, x);
            }

            return "";
        }
    };
}
