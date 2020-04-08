#pragma once
#include <vector>
namespace p992
{
    class Solution
    {
      public:
        int subarraysWithKDistinct(std::vector<int>& A, int K)
        {

            std::vector<int> window_contents(A.size(), 0);

            int res = 0;

            size_t left = 0;
            size_t distinct = 0;
            for (size_t right = 0; right < A.size(); ++right)
            {
                // add the current element to the window
                ++window_contents[A[right] - 1];
                if (window_contents[A[right] - 1] == 1) // went from zero to one - increase the number of distinct elements
                    ++distinct;

                // as long as the window contains enough distinct elements (or more), advance the left side
                while (distinct >= K)
                {
                    if (distinct == K)
                        ++res;

                    --window_contents[A[left] - 1];
                    if (window_contents[A[left] - 1] == 0) // went from one to zero - decrease the number of distinct elements
                        --distinct;
                    ++left;
                }

                // the next right will add zero or one new distinct elements, so our window must start the earliest left where we
                // had k distincts
                while (distinct <= K && left > 0)
                {
                    --left;
                    ++window_contents[A[left] - 1];
                    if (window_contents[A[left] - 1] == 1) // went from zero to one - increase number of distinct elements
                        ++distinct;
                }
            }

            return res;
        }
    };
}