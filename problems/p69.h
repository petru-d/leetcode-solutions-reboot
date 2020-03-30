#pragma once
namespace p69
{
    class Solution
    {
      public:
        int mySqrt(int x)
        {
            if (x <= 1)
                return x;
            if (x <= 3)
                return 1;

            return bsearch(2, 46340, x);
        }

      private:
        int bsearch(int left, int right, int x)
        {
            if (left + 1 >= right)
                return right * right <= x ? right : left;

            int mid = (left + right) / 2;
            auto midd = mid * mid;
            if (midd == x)
                return mid;
            if (midd < x)
                return bsearch(mid, right, x);
            // if (midd > x)
            return bsearch(left, mid, x);
        }
    };
}