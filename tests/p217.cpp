#include "pch.h"

#include "../problems/p217.h"

TEST(p217, t0)
{
    p217::Solution s;

    std::vector<int> nums = {1, 2, 3, 1};

    auto res = s.containsDuplicate(nums);

    EXPECT_TRUE(res);
}
