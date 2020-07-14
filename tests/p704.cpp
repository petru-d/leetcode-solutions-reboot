#include "pch.h"

#include "../problems/p704.h"

TEST(p704, t0)
{
    p704::Solution s;

    std::vector<int> nums = {2, 4, 5};
    auto res = s.search(nums, 1);

    EXPECT_EQ(res, -1);
}
