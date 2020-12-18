#pragma once

#include <optional>
#include <vector>
#include <string>

namespace p227
{
    class Solution
    {
      public:
        int calculate(std::string s)
        {
            auto apply_op = [](int l, char op, int r) {
                if (op == '+')
                    return l + r;
                if (op == '-')
                    return l - r;
                if (op == '/')
                    return l / r;
                if (op == '*')
                    return l * r;

                return 0;
            };

            std::vector<int> nums;
            std::vector<char> ops;

            size_t S = s.size();
            for (size_t i = 0; i < S; ++i)
            {
                if (s[i] == ' ')
                    continue;
                if ('0' <= s[i] && s[i] <= '9')
                {
                    int val = 0;
                    size_t j = i;
                    while (j < S && '0' <= s[j] && s[j] <= '9')
                    {
                        val = val * 10 + (s[j] - '0');
                        ++j;
                    }
                    nums.push_back(val);
                    i = j - 1;
                }
                else
                {
                    ops.push_back(s[i]);
                }
            }

            int result = nums[0];
            std::optional<int> low_prio_n = {};
            std::optional<char> low_prio_op = {};
            char op = ' ';
            size_t T = nums.size();
            for (size_t i = 1; i < T; ++i)
            {
                char op = ops[i - 1];
                int other = nums[i];

                if (op == '*' || op == '/')
                {
                    result = apply_op(result, op, other);
                }
                else
                {
                    if (!low_prio_n)
                    {
                        low_prio_n = result;
                    }
                    else
                    {
                        low_prio_n = apply_op(*low_prio_n, *low_prio_op, result);
                    }
                    low_prio_op = op;
                    result = other;
                }
            }

            if (low_prio_n)
                result = apply_op(*low_prio_n, *low_prio_op, result);

            return result;
        }
    };
}
