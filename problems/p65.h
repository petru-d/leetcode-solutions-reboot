#pragma once
#include <regex>
#include <string>

namespace p65
{
    // can also implement an automata or even write it with ifs
    class Solution
    {
      public:
        const std::regex& r()
        {
            static const std::string intRe = "([+\\-]?[0-9]+)";
            static const std::string decRe = "([+\\-]?(([0-9]+\\.)|([0-9]+\\.[0-9]+)|(\\.[0-9]+)))";

            static const std::string numRe = "(" + intRe + "|" + decRe + ")" + "([eE]" + intRe + ")?";

            static const std::regex r(numRe);
            return r;
        }

        bool isNumber(std::string s)
        {
            return std::regex_match(s, r());
        }
    };
}
