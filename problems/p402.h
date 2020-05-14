#pragma once
#include <algorithm>
#include <string>

namespace p402
{
    class Solution
    {
      public:
        std::string removeKdigits(std::string num, int k)
        {
            size_t N = num.size();
            if (k >= N)
                return "0";

            std::string result;
            result.reserve(N - k);

            auto clean = [](std::string&& str) -> std::string {
                if (str.empty())
                    return "0";

                auto pos_non_zero = std::find_if(str.begin(), str.end(), [](char c) { return c != '0'; });
                str = str.substr(std::distance(str.begin(), pos_non_zero));
                if (str.empty())
                    return "0";

                return str;
            };

            size_t curr = 0;
            while (k > 0 && curr < N)
            {
                if (result.empty())
                {
                    result.push_back(num[curr]);
                    ++curr;
                    continue;
                }

                if (result.back() > num[curr])
                {
                    while (!result.empty() && curr < N && result.back() > num[curr] && k > 0)
                    {
                        --k;
                        result.pop_back();
                    }
                }
                result.push_back(num[curr]);
                ++curr;
            }

            if (k > 0)
            {
                // if there are digits left to remove, it means we traversed all the input and there's no inversion left (d1 > d2)
                // - remove the tail
                while (k > 0 && !result.empty())
                {
                    result.pop_back();
                    --k;
                }
            }
            else
            {
                // no more digits to remove - add the rest of the untraversed input as it is
                result += num.substr(curr);
            }

            return clean(std::move(result));
        }
    };
}