#include "pch.h"

#include "../problems/p442.h"

TEST(p442, t0)
{
    p442::Solution s;

    std::vector<int> nums = {1, 2, 3, 1, 2, 3};

    auto res = s.findDuplicates(nums);

    std::vector<int> expected = {1, 2, 3};

    EXPECT_EQ(res, expected);
}
