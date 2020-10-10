#include "pch.h"

#include "../problems/p713.h"

TEST(p713, t0)
{
    p713::Solution s;

    std::vector<int> nums = {10, 5, 2, 6};
    auto res = s.numSubarrayProductLessThanK(nums, 100);

    EXPECT_EQ(res, 8);
}
