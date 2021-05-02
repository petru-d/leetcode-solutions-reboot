#include "pch.h"

#include "../problems/p34.h"

TEST(p34, t0)
{
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};

    p34::Solution s;
    auto res = s.searchRange(nums, 8);
    EXPECT_EQ(res, (std::vector<int>{3, 4}));

    p34::Solution2 s2;
    res = s2.searchRange(nums, 8);
    EXPECT_EQ(res, (std::vector<int>{3, 4}));
}
