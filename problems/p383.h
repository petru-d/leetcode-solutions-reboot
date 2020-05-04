#pragma once
#include <array>
#include <string>
namespace p383
{

    class Solution
    {
      public:
        bool canConstruct(std::string ransomNote, std::string magazine)
        {
            std::array<int, 26> usage = {};
            for (auto c : ransomNote)
            {
                ++usage[size_t(c) - 'a'];
            }
            for (auto c : magazine)
            {
                --usage[size_t(c) - 'a'];
            }

            return !std::any_of(usage.begin(), usage.end(), [](int i) { return i > 0; });
        }
    };
}