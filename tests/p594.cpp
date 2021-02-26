#include "pch.h"

#include "../problems/p594.h"

TEST(p594, t0)
{
    [[maybe_unused]] p594::Solution s;

    std::vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = s.findLHS(nums);

    EXPECT_EQ(res, 5);
}
