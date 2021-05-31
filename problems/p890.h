#pragma once
#include <array>
#include <string>
#include <vector>

namespace p890
{
    class Solution
    {
      public:
        std::vector<std::string> findAndReplacePattern(std::vector<std::string>& words, std::string pattern)
        {
            auto P = pattern.size();
            std::vector<std::string> result;
            for (const auto& w : words)
            {
                if (w.size() != P)
                    continue;

                std::array<char, 26> constraints = {};
                std::array<int, 26> pattern_used = {};
                bool match = true;
                for (size_t i = 0; i < P; ++i)
                {
                    if (constraints[w[i] - 'a'] == 0)
                    {
                        if (pattern_used[pattern[i] - 'a'] == 1)
                        {
                            match = false;
                            break;
                        }
                        constraints[w[i] - 'a'] = pattern[i];
                        pattern_used[pattern[i] - 'a'] = 1;
                    }
                    else
                    {
                        if (constraints[w[i] - 'a'] != pattern[i])
                        {
                            match = false;
                            break;
                        }
                    }
                }
                if (match)
                    result.push_back(std::move(w));
            }

            return result;
        }
    };
}
