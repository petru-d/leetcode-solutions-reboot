#include "pch.h"

#include "../problems/p456.h"

TEST(p456, t0)
{
    p456::Solution s;

    std::vector<int> nums = {1, 3, 2};

    auto res = s.find132pattern(nums);

    EXPECT_TRUE(res);
}
