#pragma once
#include <string>

namespace p1108
{
    class Solution
    {
      public:
        std::string defangIPaddr(std::string address)
        {
            size_t A = address.size();
            std::string result(A + 6, ' ');

            size_t dots = 0;

            for (size_t i = 0; i < A; ++i)
            {
                if (address[i] != '.')
                    result[i + 2 * dots] = address[i];
                else
                {
                    result[i + 2 * dots] = '[';
                    result[i + 2 * dots + 1] = '.';
                    result[i + 2 * dots + 2] = ']';
                    ++dots;
                }
            }

            return result;
        }
    };
}