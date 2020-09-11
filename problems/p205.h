#pragma once
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace p205
{
    class Solution
    {
      public:
        bool isIsomorphic(std::string s, std::string t)
        {
            std::unordered_map<char, char> mapping;
            std::unordered_set<char> used;

            size_t N = s.size();
            for (size_t i = 0; i < N; ++i)
            {
                const auto l = s[i] - 'a';
                const auto r = t[i] - 'a';

                auto lpos = mapping.find(l);
                if (lpos != mapping.end())
                {
                    if (lpos->second == r)
                        continue;
                    return false;
                }
                if (used.find(r) != used.end())
                    return false;

                mapping.insert({l, r});
                used.insert(r);
            }

            return true;
        }
    };
}
