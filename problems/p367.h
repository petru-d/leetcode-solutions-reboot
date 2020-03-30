#pragma once
namespace p367
{
    class Solution
    {
      public:
        bool isPerfectSquare(int num)
        {
            if (num == 0 || num == 1 || num == 4)
                return true;

            return bsearch(2, 46340, num);
        }

      private:
        bool bsearch(int left, int right, int num)
        {
            if (left + 1 >= right)
                return right * right == num || left * left == num;

            int mid = (left + right) / 2;
            auto midd = mid * mid;
            if (midd == num)
                return mid;
            if (midd < num)
                return bsearch(mid, right, num);
            // if (midd > x)
            return bsearch(left, mid, num);
        }
    };
}