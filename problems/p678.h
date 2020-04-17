#pragma once

#include <string>

namespace p678
{
    class Solution
    {
      public:
        bool checkValidString(std::string s)
        {
            int left_open = 0;
            for (auto c : s)
            {
                if (c == '(' || c == '*')
                    ++left_open;
                else
                {
                    if (left_open == 0)
                        return false;
                    --left_open;
                }
            }

            int right_open = 0;
            for (size_t i = s.size(); i >= 1; --i)
            {
                auto c = s[i - 1];

                if (c == ')' || c == '*')
                    ++right_open;
                else
                {
                    if (right_open == 0)
                        return false;
                    --right_open;
                }
            }

            return true;
        }
    };
}