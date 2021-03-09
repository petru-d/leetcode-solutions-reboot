#pragma once
#include <string>
namespace p1332
{
    class Solution
    {
      public:
        int removePalindromeSub(std::string s)
        {
            auto S = s.size();
            if (S == 0)
                return 0;
            bool is_palindrome = true;
            for (size_t i = 0; i <= S / 2; ++i)
                if (s[i] != s[S - i - 1])
                {
                    is_palindrome = false;
                    break;
                }

            return is_palindrome ? 1 : 2;
        }
    };
}
