#pragma once
#include <stack>
#include <string>
#include <vector>

namespace p32
{
    class Solution2
    {
      public:
        int longestValidParentheses(std::string s)
        {
            std::stack<std::pair<char, size_t>> par;

            std::vector<std::pair<size_t, size_t>> valids;

            auto include = [](const std::pair<size_t, size_t>& a, const std::pair<size_t, size_t>& b) {
                return a.first < b.first && b.second < a.second;
            };

            size_t result = 0;

            auto S = s.size();
            for (size_t i = 0; i < S; ++i)
            {
                if (s[i] == '(')
                    par.push({'(', i});
                else //(s[i] == ')')
                {
                    if (!par.empty() && par.top().first == '(')
                    {
                        size_t sequence_start = par.top().second;
                        size_t sequence_end = i;

                        // clean any included sequences
                        while (!valids.empty() && include({sequence_start, sequence_end}, valids.back()))
                            valids.pop_back();

                        // either merge this sequence with the one before it that is valid
                        // or simply add it to the list of valid squences
                        if (!valids.empty() && valids.back().second == sequence_start - 1)
                            valids.back().second = sequence_end;
                        else
                            valids.push_back({sequence_start, sequence_end});

                        result = std::max(result, valids.back().second - valids.back().first + 1);

                        par.pop();
                    }
                    else
                        ; // garbage - ignore
                }
            }

            return int(result);
        }
    };

    class Solution3
    {
      public:
        int longestValidParentheses(std::string s)
        {
            // (()() -1 0 1
            std::stack<size_t> par;
            par.push(-1); // next valid sequence might start at 0, we start in the garbage area
            size_t result = 0;

            auto S = s.size();
            for (size_t i = 0; i < S; ++i)
            {
                if (s[i] == '(')
                    par.push(i);
                else //(s[i] == ')')
                {
                    par.pop();
                    if (par.empty())
                        par.push(i); // next valid sequence might start at i + 1, we are in garbage area now
                    else
                        result = std::max(result, i - par.top());
                }
            }

            return int(result);
        }
    };

    class Solution
    {
      public:
        int longestValidParentheses(std::string s)
        {
            int res = 0;
            int left = 0;
            int right = 0;
            int S = int(s.size());
            for (int i = 0; i < S; ++i)
            {
                if (s[i] == '(')
                    ++left;
                else
                    ++right;

                if (left == right)
                    res = std::max(res, 2 * left);
                else if (right > left)
                    left = right = 0;
            }

            left = right = 0;
            for (int i = S - 1; i >= 0; --i)
            {
                if (s[i] == '(')
                    ++left;
                else
                    ++right;

                if (left == right)
                    res = std::max(res, 2 * left);
                else if (right < left)
                    left = right = 0;
            }

            return res;
        }
    };
}
