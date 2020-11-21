#pragma once
#include <string>
#include <stack>

namespace p394
{
    class Solution
    {
      public:
        std::string decodeString(std::string s)
        {
            auto compose = [](std::pair<int, std::string> element) {
                std::string result;
                result.reserve(element.first * element.second.size());
                for (int i = 0; i < element.first; ++i)
                    result.append(element.second);
                return result;
            };

            std::stack<std::pair<int, std::string>> res;
            res.push({-1, ""});

            auto S = s.size();
            for (size_t i = 0; i < S; ++i)
            {
                if ('0' <= s[i] && s[i] <= '9')
                {
                    int num = 0;
                    while ('0' <= s[i] && s[i] <= '9')
                    {
                        num = 10 * num + s[i] - '0';
                        ++i;
                    }
                    res.push({num, ""});
                }
                else if (']' == s[i])
                {
                    auto top = res.top();
                    res.pop();
                    res.top().second += compose(top);
                }
                else
                {
                    res.top().second.append(1, s[i]);
                }
            }

            return res.top().second;
        }
    };
}
