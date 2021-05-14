#include "pch.h"

#include "../problems/p45.h"

TEST(p45, t0)
{
    std::vector<int> nums = {2, 3, 1, 1, 4};
    p45::Solution s;
    auto res = s.jump(nums);
    EXPECT_EQ(res, 2);

    p45::Solution2 s2;
    res = s2.jump(nums);
    EXPECT_EQ(res, 2);
}
