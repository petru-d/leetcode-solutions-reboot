#include "pch.h"

#include "../problems/p1649.h"

TEST(p1649, t0)
{
    p1649::Solution s;

    std::vector<int> nums = {1, 5, 6, 2};
    auto res = s.createSortedArray(nums);

    EXPECT_EQ(res, 1);
}
