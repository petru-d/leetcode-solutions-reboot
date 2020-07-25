#include "pch.h"

#include "../problems/p260.h"

TEST(p260, t0)
{
    p260::Solution s;

    std::vector<int> nums = {1, 2, 1, 2, 3, 4};

    auto res = s.singleNumber(nums);

    std::vector<int> expected = {3, 4};

    EXPECT_EQ(res, expected);
}
