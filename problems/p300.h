#pragma once
#include <vector>

namespace p300
{
    class Solution
    {
      public:
        // patience sorting
        int lengthOfLIS2(std::vector<int>& nums)
        {
            if (nums.empty())
                return 0;
            std::vector<int> piles;
            for (int i = 0; i < nums.size(); i++)
            {
                auto it = std::lower_bound(piles.begin(), piles.end(), nums[i]);
                if (it == piles.end())
                    piles.push_back(nums[i]);
                else
                    *it = nums[i];
            }
            return int(piles.size());
        }

        int lengthOfLIS(std::vector<int>& nums)
        {
            size_t N = nums.size();

            std::vector<size_t> pred(N, 0);
            std::vector<size_t> m(N + 1, 0);

            size_t L = 0;
            for (size_t i = 0; i < N; ++i)
            {
                // Binary search for the largest positive j ≤ L such that X[M[j]] <= X[i]
                size_t lo = 1;
                size_t hi = L;
                while (lo <= hi)
                {
                    auto mid = (lo + hi) / 2 + (lo + hi) % 2;
                    if (nums[m[mid]] < nums[i])
                        lo = mid + 1;
                    else
                        hi = mid - 1;
                }
                // After searching, lo is 1 greater than the length of the longest prefix of X[i]
                auto newL = lo;

                // The predecessor of X[i] is the last index of  the subsequence of length newL-1
                pred[i] = m[newL - 1];
                m[newL] = i;

                L = std::max(newL, L);
            }

            // Reconstruct the longest increasing subsequence
            std::vector<int> seq(L, 0);
            auto k = m[L];
            for (auto i = L; i > 0; --i)
            {
                seq[i - 1] = nums[k];
                k = pred[k];
            }

            return int(seq.size());
        }
    };
}
