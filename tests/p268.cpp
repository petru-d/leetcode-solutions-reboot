#include "pch.h"

#include "../problems/p268.h"

TEST(p268, t0)
{
    p268::Solution s;
    std::vector<int> nums = {3, 0, 1};
    auto res = s.missingNumber1(nums);
    EXPECT_EQ(res, 2);
    res = s.missingNumber2(nums);
    EXPECT_EQ(res, 2);
}
