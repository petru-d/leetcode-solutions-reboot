#pragma once
#include <string>

namespace p657
{
    class Solution
    {
      public:
        bool judgeCircle(std::string moves)
        {
            struct Point
            {
                int X = 0;
                int Y = 0;
            };

            Point curr_pos{0, 0};

            for (auto m : moves)
            {
                if (m == 'U')
                    ++curr_pos.Y;
                else if (m == 'D')
                    --curr_pos.Y;
                else if (m == 'L')
                    --curr_pos.X;
                else // if (m == 'R')
                    ++curr_pos.X;
            }

            return curr_pos.X == 0 && curr_pos.Y == 0;
        }
    };
}
