#pragma once
#include <string>
namespace p1576
{
    class Solution
    {
      public:
        std::string modifyString(std::string s)
        {
            auto solve0 = []() { return 'a'; };

            auto solve1 = [](char c1) { return c1 == 'a' ? 'b' : 'a'; };

            auto solve2 = [&](char c1, char c2) {
                if (c1 > c2)
                    std::swap(c1, c2);

                if (c1 != 'a')
                    return 'a';
                if (c2 != 'z')
                    return 'z';

                return 'b';
            };

            auto S = s.size();
            for (size_t i = 0; i < S; ++i)
            {
                if (s[i] != '?')
                    continue;

                char c1 = 0;
                if (i > 0)
                    c1 = s[i - 1];

                char c2 = 0;
                if (i < S - 1 && s[i + 1] != '?')
                {
                    if (c1 == 0)
                        c1 = s[i + 1];
                    else
                        c2 = s[i + 1];
                }

                if (c1 == 0 && c2 == 0)
                    s[i] = solve0();
                else if (c2 == 0)
                    s[i] = solve1(c1);
                else
                    s[i] = solve2(c1, c2);
            }

            return std::move(s);
        }
    };
}
