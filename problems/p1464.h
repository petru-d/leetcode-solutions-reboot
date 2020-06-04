#pragma once

#include <vector>

namespace p1464
{
    class Solution
    {
      public:
        int maxProduct(std::vector<int>& nums)
        {
            int biggest = -1;
            int second_biggest = -1;
            for (auto n : nums)
            {
                if (n > biggest)
                {
                    second_biggest = biggest;
                    biggest = n;
                }
                else if (n > second_biggest)
                {
                    second_biggest = n;
                }
            }

            return (biggest - 1) * (second_biggest - 1);
        }
    };
}