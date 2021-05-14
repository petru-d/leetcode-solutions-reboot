#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p816
{
    class Solution
    {

      public:
        std::vector<std::string> ambiguousCoordinates(std::string s)
        {
            //(a,bcd)
            std::vector<std::string> result;
            // pos_comma == x means we are putting the comma after the character at index x.
            for (size_t pos_comma = 1; pos_comma < s.size() - 2; ++pos_comma)
            {
                auto left = get_nums(std::string_view(s.data() + 1, pos_comma));
                auto right = get_nums(std::string_view(s.data() + 1 + pos_comma, s.size() - 2 - pos_comma));
                auto combined = combine_options(left, right);
                std::move(combined.begin(), combined.end(), std::back_inserter(result));
            }

            return result;
        }

        std::vector<std::string> combine_options(std::vector<std::string>& left, std::vector<std::string>& right)
        {
            using namespace std::string_literals;

            std::vector<std::string> result;

            for (size_t l = 0; l < left.size(); ++l)
                for (size_t r = 0; r < right.size(); ++r)
                {
                    std::string res = "("s + left[l] + ", "s + right[r] + ")"s;
                    result.push_back(std::move(res));
                }

            return result;
        }

        std::vector<std::string> get_nums(std::string_view s)
        {
            if (s.empty())
                return {};

            // if it starts and ends with '0', it can only be "0" if it has length 1, otherwise no options
            if (s.front() == s.back() && s.front() == '0')
                return s.size() == 1 ? std::vector<std::string>{"0"} : std::vector<std::string>{};

            // if it starts with '0' and we're here, it means it doesn't end with '0', so it can only be "0.rest"
            if (s.front() == '0')
                return {std::string(1, s[0]).append(1, '.') + std::string(s.substr(1))};

            // if it ends with '0' and we're here, it measn it doesn't start with '0', so it can only be "itself"
            if (s.back() == '0')
                return {std::string(s)};

            // it doesn't start with zero, it doesn't end with zero - we can put the dot between any of the digits or not at all
            std::vector<std::string> result = {std::string(s)};
            for (size_t pos = 1; pos < s.size(); ++pos)
                result.push_back(std::string(s.substr(0, pos)).append(1, '.') + std::string(s.substr(pos)));

            return result;
        }
    };
}
