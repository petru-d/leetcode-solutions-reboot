#include "pch.h"

#include "../problems/p581.h"

TEST(p581, t0)
{
    p581::Solution s;
    std::vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
    auto res = s.findUnsortedSubarray(nums);
    EXPECT_EQ(res, 5);
}
