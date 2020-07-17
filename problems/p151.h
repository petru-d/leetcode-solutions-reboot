#pragma once
#include <string>

namespace p151
{
    class Solution
    {
      public:
        std::string reverseWords(std::string s)
        {
            std::reverse(s.begin(), s.end());

            size_t curr_pos = 0;
            bool done = false;
            while (!done)
            {
                size_t next_pos = curr_pos;
                size_t spaces = 0;
                while (next_pos < s.size() && s[next_pos] == ' ')
                {
                    ++next_pos;
                    ++spaces;
                }
                done = true;
                while (next_pos < s.size() && s[next_pos] != ' ')
                {
                    done = false;
                    ++next_pos;
                }

                if (done)
                    break;

                std::reverse(s.begin() + curr_pos, s.begin() + next_pos);

                curr_pos = next_pos - spaces + 1;
            }

            s.erase(s.find_last_not_of(" ") + 1);
            return s;
        }
    };
}
