#pragma once
#include <algorithm>
#include <string>
#include <vector>

namespace p524
{
    class Solution
    {
      public:
        std::string findLongestWord(std::string s, std::vector<std::string>& d)
        {
            std::sort(d.rbegin(), d.rend(), [](const std::string& l, const std::string& r) {
                if (l.size() != r.size())
                    return l.size() < r.size();

                return l > r;
            });

            auto included = [](const std::string& s, const std::string& w) {
                size_t s_pos = 0;

                for (const auto l : w)
                {
                    if (s_pos >= s.size())
                        return false;

                    s_pos = s.find(l, s_pos);
                    if (s_pos == std::string::npos)
                        return false;
                    ++s_pos;
                }
                return true;
            };

            std::string best = "";
            for (const auto& w : d)
            {
                if (w.size() <= best.size())
                    break;

                if (included(s, w))
                    best = w;
            }

            return best;
        }
    };
}
