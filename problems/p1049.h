#pragma once

#include <numeric>
#include <vector>

namespace p1049
{
    class Solution
    {
      public:
        int lastStoneWeightII(std::vector<int>& stones)
        {
            // consider s0, s1, ..., sn-1
            // if we smash si with sj, we replace them with x = |si - sj| (this is either si - sj or - sj + si)
            // later, when x is smashed against sk, we replace x and sk with |sk - x|
            // this is either sk - x or - sk + x, so either
            //   sk - si + sj, sk + si - sj, -sk + si - sj or -sk - sj + si

            // Different choices of sk will mean different versions of (+-si +-sj +-sk) will be realized.
            // Not all are possible! Depending on the actual values of the stones, only some will be realizable.

            // So yes, the final stone's value is always something like +-s0 +-s1 ... +-sn-1
            // But, not all the +- combinations are valid as a final stone value.
            // N.b. The Hint1 is not really 100% accurate. Try to realize -2 +7 +4 -1 +8 -1 (=15) for example.
            // Or any negative number for that matter.

            // Nevertheless, our minimum will be amongst the +- combinations that are realizable.
            // So choosing the + and - such that the total sum is minimal will yeld some value.
            // How do we know this +- choice is among the valid ones?

            // Let's say the minimum value by partitioning the stones into two groups
            // G1 = -a -b -c ...
            // G2 = +x +y +z ...
            // And the delta between the groups is minimal.

            // Can we prove that this is always realizable? ... idk

            //... anyway, we run a 0/1 Knapsack problem, targeting S/2

            auto S = std::accumulate(stones.begin(), stones.end(), 0);
            auto target = S / 2;

            size_t closest_to_target = 0;

            std::vector<bool> can_make_w(target + size_t(1), false);
            can_make_w[0] = true;

            auto can_make_w_next = can_make_w;

            for (size_t s = 0; s < stones.size(); ++s)
            {
                for (size_t w = 1; w < can_make_w_next.size(); ++w)
                {
                    can_make_w_next[w] = can_make_w[w];
                    if (w >= stones[s])
                        can_make_w_next[w] = can_make_w_next[w] | can_make_w[w - stones[s]];

                    if (can_make_w_next[w] && closest_to_target < w)
                        closest_to_target = w;
                }

                std::swap(can_make_w, can_make_w_next);
            }

            return static_cast<int>(S - 2 * closest_to_target);
        }
    };
}
