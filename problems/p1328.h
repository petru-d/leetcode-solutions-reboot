#pragma once
#include <string>

namespace p1328
{
    class Solution
    {
      public:
        std::string breakPalindrome(std::string palindrome)
        {
            // If the palindrome has only one letter, we can't break it.
            if (palindrome.size() <= 1)
                return "";

            // Most palindromes can be broken by replacing the first non-'a' with 'a'.
            // Exceptions:
            // - only a characters: "aaaa..."
            // - odd numbered palindromes containing only "a" with the exception of the middle.

            size_t P = palindrome.size();
            for (size_t i = 0; i < P; ++i)
                if (palindrome[i] != 'a' && (i != P / 2 || P % 2 == 0))
                {
                    palindrome[i] = 'a';
                    return palindrome;
                }

            // Being here means no replacement was possible, because there were only 'a' characters.
            // Replace the last character with 'b' then.
            palindrome.back() = 'b';

            return palindrome;
        }
    };
}