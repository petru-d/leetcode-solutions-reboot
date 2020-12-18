#include "pch.h"

#include "../problems/p334.h"

TEST(p334, t0)
{
    p334::Solution s;

    std::vector<int> nums = {1, 2, 3, 4};
    auto res = s.increasingTriplet(nums);

    EXPECT_TRUE(res);
}
