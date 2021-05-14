#include "pch.h"

#include "../problems/p665.h"

TEST(p665, t0)
{
    p665::Solution s;
    std::vector<int> nums = {4, 2, 3};
    auto res = s.checkPossibility(nums);
    EXPECT_TRUE(res);
}
