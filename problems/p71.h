#pragma once
#include <string>
#include <vector>

namespace p71
{
    class Solution
    {
      public:
        std::string simplifyPath(std::string path)
        {
            std::vector<std::string> tokens;
            std::string current_token;

            size_t i = 0;
            for (auto p : path)
            {
                if (p == '/')
                {
                    if (!current_token.empty())
                        tokens.push_back(std::move(current_token));
                    current_token = "";
                }
                else
                {
                    current_token.append(1, p);
                }
                ++i;
            }
            if (!current_token.empty())
                tokens.push_back(std::move(current_token));

            std::vector<std::string> simple_tokens;
            for (auto& t : tokens)
            {
                if (t == "..")
                {
                    if (!simple_tokens.empty())
                        simple_tokens.pop_back();
                }
                else if (t == ".")
                {
                }
                else
                    simple_tokens.push_back(std::move(t));
            }

            if (simple_tokens.empty())
                return "/";

            std::string result;
            for (auto& s : simple_tokens)
            {
                result.append(1, '/');
                result += std::move(s);
            }

            return result;
        }
    };
}
