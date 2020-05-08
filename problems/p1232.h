#pragma once
#include <vector>

namespace p1232
{
    class Solution
    {
      public:
        bool checkStraightLine(std::vector<std::vector<int>>& coordinates)
        {
            auto C = coordinates.size();
            if (C <= 1)
                return false;
            if (C == 2)
                return true;

            int x0 = coordinates[0][0];
            int y0 = coordinates[0][1];
            int x1 = coordinates[1][0];
            int y1 = coordinates[1][1];

            auto x1_x0 = x1 - x0;
            auto y1_y0 = y1 - y0;

            for (size_t c = 2; c < C; ++c)
            {
                int xc = coordinates[c][0];
                int yc = coordinates[c][1];

                if (y1_y0 * (xc - x0) != (yc - y0) * x1_x0)
                    return false;
            }

            return true;
        }
    };
}