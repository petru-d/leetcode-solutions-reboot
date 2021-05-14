#pragma once
#include <vector>

namespace p45
{
    class Solution
    {
      public:
        // from the current position, we always jump to the point that maximizes the reach for the next jump
        // ... 3 5 2 1 4 1 6 2 ...
        // if we are at 3, the choice is between 5, 2, and 1
        // - jumping to 5 would mean that our next interval would be 2 1 4 1 6
        // - jumping to 2 would mean that our next interval would be 1 4
        // - jumping to 1 would mean that our next interval would be 4
        // so we jump to 5

        // why it works: if we choose anything else than the point that maximizes the reach,
        // we will have less choice for the next jump and the choices will be earlier.
        // so this would end up in a larger amount of jumps

        int jump(std::vector<int>& nums)
        {
            int jumps = 0;
            size_t currentJumpEnd = 0;
            auto N = nums.size();
            size_t farthestCurrJump = 0;
            for (size_t i = 0; i < N - 1; ++i)
            {
                // scan to see what is the landing that would maximize the reach for the next jump
                farthestCurrJump = std::max(farthestCurrJump, i + size_t(nums[i]));
                // jump to the chosen landing
                if (i == currentJumpEnd)
                {
                    ++jumps;
                    currentJumpEnd = farthestCurrJump;
                }
            }

            return jumps;
        }
    };

    class Solution2
    {
      public:
        int jump(std::vector<int>& nums)
        {
            auto N = nums.size();
            std::vector<int> best(N, 0);

            for (size_t i = 1; i < N; ++i)
            {
                auto best_i = std::numeric_limits<int>::max();

                for (int j = i - 1; j >= 0; --j)
                    if (nums[j] + j >= i)
                    {
                        if (best[j] != std::numeric_limits<int>::max())
                            best_i = std::min(best_i, 1 + best[j]);
                        if (best_i == 1)
                            break;
                    }

                best[i] = best_i;
            }

            return best.back();
        }
    };
}
