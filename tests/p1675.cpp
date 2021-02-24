#include "pch.h"

#include "../problems/p1675.h"

TEST(p1675, t0)
{
    [[maybe_unused]] p1675::Solution s;

    std::vector<int> nums = {4, 1, 5, 20, 3};
    auto res = s.minimumDeviation(nums);

    EXPECT_EQ(res, 3);
}
