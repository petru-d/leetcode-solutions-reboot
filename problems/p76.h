#pragma once
#include <algorithm>
#include <array>
#include <string>

namespace p76
{
    class Solution
    {
      public:
        std::string minWindow(std::string s, std::string t)
        {
            // sliding window
            // - while t is not satisfied, increase right (when satisfied, register solution candidate)
            // - increase right until a char from t is found (or when reaching the end of s)
            // - decrease left while t satisfied (but don't de-satisfy) (if any decrease happened, register solution candidate)
            // N.B. : right is one-over (stl style)

            // How much "need" for the specific char. Satisfied means that the "need" is zero or less.
            // Initially we need all chars.
            std::array<int, 256> satisfaction;
            for (size_t i = 0; i < 256; ++i)
                satisfaction[i] = std::numeric_limits<int>::min();

            for (const auto& c : t)
            {
                if (satisfaction[c + size_t(128)] == std::numeric_limits<int>::min())
                    satisfaction[c + size_t(128)] = 0;
                ++satisfaction[c + size_t(128)];
            }

            // adds a char to satisfaction. returns true if the char contributes to satisfaction
            auto add_char = [&satisfaction](char c, bool count_only_full_satisfaction) {
                if (satisfaction[c + size_t(128)] == std::numeric_limits<int>::min())
                    return false;

                --satisfaction[c + size_t(128)];
                if (count_only_full_satisfaction)
                    return 0 <= satisfaction[c + size_t(128)];
                else
                    return true;
            };

            // checks if we can remove a char from the satisfaction while remaining satisfied
            // if yes, also removes the char
            auto can_remove_char = [&satisfaction](char c) {
                if (satisfaction[c + size_t(128)] == std::numeric_limits<int>::min())
                    return true;

                if (satisfaction[c + size_t(128)] + 1 <= 0)
                {
                    ++satisfaction[c + size_t(128)];
                    return true;
                }
                return false;
            };

            std::string solution;

            size_t left = 0;
            size_t right = 0;

            auto T = t.size();
            size_t t_satisfied = 0;

            auto S = s.size();
            while (right < S)
            {
                bool added = add_char(s[right++], true);
                if (added)
                {
                    ++t_satisfied;
                    if (T == t_satisfied)
                    {
                        // found the left-most starting window where t is satisfied
                        solution = s.substr(left, right - left);
                        if (right - left == T)
                            return solution;
                        break;
                    }
                }
            }
            // If we consumed the whole std::string and t is still not satisfied, there is no solution.
            if (solution.empty())
                return solution;

            // push left as far as possible without dissatifying
            bool could_decrease = false;
            while (can_remove_char(s[left]))
            {
                could_decrease = true;
                ++left;
            }
            if (could_decrease && right - left < solution.size())
            {
                solution = s.substr(left, right - left);
                if (right - left == T)
                    return solution;
            }

            while (right < S)
            {
                bool added = add_char(s[right++], false);
                if (added)
                {
                    could_decrease = false;
                    while (can_remove_char(s[left]))
                    {
                        could_decrease = true;
                        ++left;
                    }
                    if (could_decrease && right - left < solution.size())
                    {
                        solution = s.substr(left, right - left);
                        if (right - left == T)
                            return solution;
                    }
                }
            }

            return solution;
        }
    };
}