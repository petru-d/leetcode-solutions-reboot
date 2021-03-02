#include "pch.h"

#include "../problems/p480.h"

TEST(p480, t0)
{
    p480::Solution s;
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = s.medianSlidingWindow(nums, 3);

    EXPECT_EQ(res, (std::vector<double>{1, -1, -1, 3, 5, 6}));
}
