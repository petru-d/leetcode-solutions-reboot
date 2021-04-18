#pragma once
#include <vector>

namespace p667
{
    class Solution
    {
      public:
        std::vector<int> constructArray(int n, int k)
        {
            // 1 2 ... n // 1 // 1 diff

            // 1 n 2 3 ... n-1  //n-1, n-2, 1 // 3 diffs
            // 1 n n-1 n-2 .. 2 //n-1, 1 // 2 diffs

            // 1 n 2 n-1 3 .. n-2 //n-1, n-2, n-3, n-4, 1 // 5 diffs
            // 1 n 2 n-1 n-2 ...3 //n-1, n-2, n-3, 1 // 4 diffs

            // 1 n 2 n-1 3 n-2 4 .. n-3 // n-1, n-2, n-3, n-4, n-5, n-6, 1 // 7 diffs
            // 1 n 2 n-1 3 n-2 n-3 .. 4 // n-1, n-2, n-3, n-4, n-5, 1 // 6 diffs

            std::vector<int> result;
            result.reserve(size_t(n));

            // number of pairs (i, n-i+1) before the ascending or descending sequence starts
            // k == 1 -> 0
            // k == 2 -> 1
            // k == 3 -> 1
            // k == 4 -> 2
            // k == 5 -> 2

            // add the pairs
            int pairs_number = k % 2 == 1 ? (k + 1) / 2 - 1 : k / 2;
            for (int i = 1; i <= pairs_number; ++i)
            {
                result.push_back(i);
                result.push_back(n - i + 1);
            }

            if (k % 2 == 1)
            {
                // fill in with ascending starting from pairs_number + 1
                int curr = pairs_number + 1;
                while (result.size() < size_t(n))
                    result.push_back(curr++);
            }
            else
            {
                // fill in with descending starting from last element
                int curr = result.back() - 1;
                while (result.size() < size_t(n))
                    result.push_back(curr--);
            }

            return result;
        }
    };
}
