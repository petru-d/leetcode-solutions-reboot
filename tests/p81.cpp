#include "pch.h"

#include "../problems/p81.h"

TEST(p81, t0)
{
    p81::Solution s;

    std::vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    auto res = s.search(nums, 0);

    EXPECT_TRUE(res);
}
