#pragma once

#include <array>
#include <string>

namespace p1154
{
    class Solution
    {
      public:
        int dayOfYear(std::string date)
        {
            int year = atoi(date.substr(0, 4).c_str());
            int month = atoi(date.substr(5, 2).c_str());
            int day = atoi(date.substr(8, 2).c_str());

            bool leap_year = year % 4 == 0;
            if (leap_year && year % 100 == 0)
                leap_year = false;
            if (!leap_year && year % 400 == 0)
                leap_year = true;

            std::array<int, 12> day_counts = {31, leap_year ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            int res = 0;
            for (size_t m = 1; m < month; ++m)
                res += day_counts[m - 1];

            res += day;

            return res;
        }
    };
}
