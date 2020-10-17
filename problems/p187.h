#pragma once

#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

namespace p187
{
    class Solution
    {
      public:
        std::vector<std::string> findRepeatedDnaSequences(std::string s)
        {

            auto getbits = [](char c) { return uint8_t(c & 0b111); };

            auto add_to_sequence = [&getbits](uint32_t sequence, char c) {
                sequence &= 0b11000111111111111111111111111111;
                sequence <<= 3;
                sequence |= getbits(c);
                return sequence;
            };

            uint32_t sequence = 0;
            for (size_t i = 0; i < 10; ++i)
                sequence = add_to_sequence(sequence, s[i]);

            std::vector<std::string> result;

            std::unordered_map<uint32_t, size_t> counter = {{sequence, 1}};
            size_t S = s.size();
            for (size_t i = 10; i < S; ++i)
            {
                sequence = add_to_sequence(sequence, s[i]);

                auto pos = counter.find(sequence);
                if (pos == counter.end())
                    counter.insert({sequence, 1});
                else
                {
                    if (pos->second == 1)
                        result.push_back(s.substr(i - 9, 10));
                    ++pos->second;
                }
            }

            return result;
        }
    };
}
