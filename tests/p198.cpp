#include "pch.h"

#include "../problems/p198.h"

TEST(p198, t0)
{
    p198::Solution s;

    std::vector<int> nums = {1, 2, 3, 1};
    auto res = s.rob(nums);

    EXPECT_EQ(res, 4);
}
