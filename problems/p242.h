#pragma once
#include <array>
#include <string>
namespace p242
{
    class Solution
    {
      public:
        bool isAnagram(std::string s, std::string t)
        {
            std::array<size_t, 26> ss = {};
            std::array<size_t, 26> tt = {};

            for (auto c : s)
                ++ss[c - 'a'];
            for (auto c : t)
                ++tt[c - 'a'];

            return ss == tt;
        }
    };
}
