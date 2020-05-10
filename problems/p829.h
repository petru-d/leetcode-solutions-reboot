#pragma once
namespace p829
{
    class Solution
    {
      public:
        int consecutiveNumbersSum(int N)
        {
            int result = 0;
            int NN = 2 * N;
            for (int k = 1; k < NN; ++k)
            {
                int ksum = k * k - k;
                if (ksum >= NN)
                    break;
                if (NN % k == 0 && ((NN - ksum) % (2 * k) == 0))
                    ++result;
            }

            return result;
        }
    };
}