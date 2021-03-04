#include "pch.h"

#include "../problems/p413.h"

TEST(p413, t0)
{
    p413::Solution s;

    std::vector<int> nums{1, 2, 3, 4};
    auto res = s.numberOfArithmeticSlices(nums);
    EXPECT_EQ(res, 3);
}
