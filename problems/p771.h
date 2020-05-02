#pragma once
#include <bitset>
#include <string>
namespace p771
{
    // or use hashset
    class Solution
    {
      public:
        int numJewelsInStones(std::string J, std::string S)
        {
            std::bitset<52> h = {};
            for (auto c : J)
                if (c >= 'a')
                    h.set(size_t(c) - 'a' + 26);
                else
                    h.set(size_t(c) - 'A');

            int total = 0;
            for (auto c : S)
            {

                if (c >= 'a' && h[size_t(c) - 'a' + 26])
                    ++total;
                if (c < 'a' && h[size_t(c) - 'A'])
                    ++total;
            }

            return total;
        }
    };

}