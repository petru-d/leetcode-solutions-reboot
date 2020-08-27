#pragma once
#include <string>

namespace p1556
{
    class Solution
    {
      public:
        std::string thousandSeparator(int n)
        {
            std::string result = std::to_string(n);
            size_t dots_count = (result.size() - 1) / 3;

            result += std::string(dots_count, '.');

            size_t curr = result.size() - 1;
            while (dots_count > 0)
            {
                std::swap(result[curr], result[curr - dots_count]);
                --curr;
                std::swap(result[curr], result[curr - dots_count]);
                --curr;
                std::swap(result[curr], result[curr - dots_count]);
                --curr;
                --curr;
                --dots_count;
            }

            return result;
        }
    };
}
