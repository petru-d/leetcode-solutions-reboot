#include "pch.h"

#include "../problems/p229.h"

TEST(p229, t0)
{
    p229::Solution s;

    std::vector<int> nums = {1, 1, 1, 2, 3, 3, 3};
    auto res = s.majorityElement(nums);

    std::vector<int> expected = {1, 3};

    EXPECT_EQ(expected, res);
}
