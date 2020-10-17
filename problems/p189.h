#pragma once
#include <vector>

namespace p189
{
    // another cute solution:

    // 1 2 3 4 5 6 7 , 3
    // reverse everything once:
    // 7 6 5 4 3 2 1
    // reverse again first k:
    // 5 6 7 4 3 2 1
    // reverse again last n - k:
    // 5 6 7 1 2 3 4

    class Solution
    {
      public:
        size_t gcd(size_t N, size_t K)
        {
            if (K > N)
                std::swap(N, K);

            while (true)
            {
                auto [q, r] = std::div(int(N), int(K));
                if (r == 0)
                    return size_t(K);
                N = K;
                K = r;
            }
            return 0;
        }

        void rotate(std::vector<int>& nums, int k)
        {
            size_t N = nums.size();
            size_t K = k % N;
            if (N == 0 || K == 0)
                return;

            for (size_t start = 0; start < gcd(N, K); ++start)
            {
                int hand = nums[start];
                size_t curr_index = start;
                do
                {
                    auto oldhand = hand;

                    if (curr_index < N - K)
                    {
                        curr_index = curr_index + K;
                    }
                    else
                    {
                        curr_index = curr_index - N + K;
                    }

                    hand = nums[curr_index];
                    nums[curr_index] = oldhand;

                } while (curr_index != start);
            }
        }
    };
}
