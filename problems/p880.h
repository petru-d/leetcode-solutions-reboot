#pragma once
#include <string>

namespace p880
{
    class Solution
    {
      public:
        std::string decodeAtIndex(std::string S, int K)
        {
            uint64_t total_size = 0;
            for (size_t i = 0; i < S.size(); ++i)
            {
                if (is_letter(S[i]))
                    ++total_size;
                else
                    total_size *= get_digit(S[i]);
            }

            for (size_t s = S.size(); s > 0; --s)
            {
                auto curr_char = S[s - 1];

                K %= total_size;

                if (K == 0 && is_letter(curr_char))
                    return std::string(1, curr_char);

                if (is_letter(curr_char))
                    --total_size;
                else
                    total_size /= get_digit(curr_char);
            }

            return "";
        }

        bool is_letter(const char c)
        {
            return 'a' <= c && c <= 'z';
        }

        int get_digit(const char c)
        {
            return c - '0';
        }
    };
}
