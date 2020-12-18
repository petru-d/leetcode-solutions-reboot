#pragma once
#include <vector>

namespace p59
{
    class Solution
    {
      public:
        std::vector<std::vector<int>> generateMatrix(int n)
        {
            std::vector<std::vector<int>> res(size_t(n), std::vector<int>(size_t(n), 0));

            int curr = 1;
            for (int i = 0; i <= n / 2; ++i)
            {
                // layer i: [i, i] -> [i, n - i - 2]
                //          [i, n - i - 1] -> [n - i - 2, n - i - 1]
                //          [n - i - 1, n - i - 1] -> [n - i - 1, i + 1]
                //          [n - i - 1, i] -> [i + 1, i]
                for (int k = i; k <= n - i - 2; ++k)
                    res[i][k] = curr++;
                for (int k = i; k <= n - i - 2; ++k)
                    res[k][n - i - 1] = curr++;
                for (int k = n - i - 1; k >= i + 1; --k)
                    res[n - i - 1][k] = curr++;
                for (int k = n - i - 1; k >= i + 1; --k)
                    res[k][i] = curr++;
            }

            if (n % 2 == 1)
                res[n / 2][n / 2] = n * n;

            return res;
        }
    };
}
