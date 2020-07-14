#pragma once

namespace p1344
{
    class Solution
    {
      public:
        double angleClock(int hour, int minutes)
        {
            double a_h = 30 * (hour % 12) + minutes / 2.0;

            double a_m = (minutes % 60) * 6;

            double result = a_h > a_m ? a_h - a_m : a_m - a_h;
            if (result > 180)
                result = 360 - result;

            return result;
        }
    };
}
