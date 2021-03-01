#pragma once
#include <algorithm>
#include <stack>
#include <string>

namespace p1249
{
    class Solution
    {
      public:
        std::string minRemoveToMakeValid(std::string s)
        {
            size_t S = s.size();

            std::stack<size_t> remove;

            for (size_t i = 0; i < S; ++i)
            {
                if (s[i] != '(' && s[i] != ')')
                    continue;

                if (s[i] == ')')
                {
                    if (remove.empty() || s[remove.top()] == ')')
                        remove.push(i);
                    else
                        remove.pop();
                }
                else // s[i] == ')'
                {
                    remove.push(i);
                }
            }

            while (!remove.empty())
            {
                auto r = remove.top();
                s[r] = '_';
                remove.pop();
            }

            std::string result;
            result.reserve(s.size());
            std::copy_if(s.begin(), s.end(), std::back_inserter(result), [](char c) { return c != '_'; });

            return result;
        }
    };
}
