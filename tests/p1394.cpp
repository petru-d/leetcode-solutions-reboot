#include "pch.h"

#include "../problems/p1394.h"

TEST(p1394, t0)
{
    p1394::Solution s;

    std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4};

    auto res = s.findLucky(nums);

    EXPECT_EQ(res, 3);
}
