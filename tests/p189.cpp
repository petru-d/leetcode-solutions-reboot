#include "pch.h"

#include "../problems/p189.h"

TEST(p189, t0)
{
    p189::Solution s;

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    s.rotate(nums, 3);

    std::vector<int> expected = {5, 6, 7, 1, 2, 3, 4};
    EXPECT_EQ(nums, expected);
}
