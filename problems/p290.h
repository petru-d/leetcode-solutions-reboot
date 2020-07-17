#pragma once

#include <array>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>

namespace p290
{
    class Solution
    {
      public:
        bool wordPattern(std::string pattern, std::string str)
        {
            std::array<std::string, 26> constraints;
            std::map<std::string, size_t> tokens;

            std::stringstream ss(str);

            for (size_t p = 0; p < pattern.size(); ++p)
            {
                std::string token;
                ss >> token;

                if (token.empty())
                    return false;

                auto index = size_t(pattern[p]) - 'a';

                auto [pos, ok] = tokens.emplace(token, index);
                if (ok)
                {
                    // we did not see this token before add it to constraints and continue
                    if (!constraints[index].empty())
                        return false;
                    constraints[index] = token;
                }
                else
                {
                    // the token is already present in the map - verify that it corresponds to the correct index
                    if (pos->second != index)
                        return false;
                }
            }

            return ss.eof();
        }
    };
}
