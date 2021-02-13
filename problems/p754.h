#pragma once

namespace p754
{
    /*
    From discussion:
    The crux of the problem is to put + and - signs on the numbers 1, 2, 3, ..., k so that the sum is target.

     k is the smallest number with S = 1 + 2 + ... + k >= target
     if S == target, 
        return k
     else (S > k)
      delta = S - target
      if delta is even - switch the sign of the number delta/2 -> return k
      else (delta is odd)
        consider numbers S = 1 + 2 + .. + k + (k + 1) -> new_delta = delta + k+1
        if new_delta is even (meaning k+1 is odd) we need to switch only one sign in the series till k+1 ->return k + 1
        else (new_delta is odd) (means k+1 is even) -> k+2 is odd -> new_new_delta = new_delta + k+2 is even -> return k + 2
    */
    class Solution
    {
      public:
        int reachNumber(int target)
        {
            target = std::abs(target);

            double k = (sqrt(1 + 8 * double(target)) - 1) / 2.0;
            int n = int(std::ceil(k));
            int N = (n + 1) * n / 2;
            int delta = N - target;

            return delta % 2 == 0 ? n : n + 1 + n % 2;
        }
    };
}
