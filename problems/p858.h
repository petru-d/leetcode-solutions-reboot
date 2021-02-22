#pragma once

namespace p858
{
    class Solution
    {
      public:
        int mirrorReflection(int p, int q)
        {
            if (q == 0)
                return 0;

            if (p % q == 0)
            {
                auto k = p / q;
                if (k % 2 == 0)
                    return 2;
                return 1;
            }

            int curr_coord = q;
            bool left = false;
            bool increase = true;

            while (true)
            {
                curr_coord = increase ? curr_coord + q : curr_coord - q;

                if (curr_coord == p)
                {
                    return left ? 1 : 2;
                }
                if (curr_coord == 0)
                    return 0;

                // went out of bounds, change direction and bring in bounds
                if (0 > curr_coord || curr_coord > p)
                {
                    increase = !increase;
                    if (curr_coord < 0)
                        curr_coord = (-curr_coord);
                    if (curr_coord > p)
                        curr_coord = 2 * p - curr_coord;
                }

                // change side
                left = !left;
            }

            return -1;
        }
    };
}
