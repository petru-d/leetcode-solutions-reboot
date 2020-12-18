#include "pch.h"

#include "../problems/p416.h"

TEST(p416, t0)
{
    p416::Solution s;

    std::vector<int> nums = {2, 3, 5};
    auto res = s.canPartition(nums);

    EXPECT_TRUE(res);
}
