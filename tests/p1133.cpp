#include "pch.h"

#include "../problems/p1133.h"

TEST(p1133, t0)
{
    std::vector<int> nums = {1, 2, 3, 3};
    p1133::Solution s;
    auto res = s.largestUniqueNumber(nums);
    EXPECT_EQ(res, 2);

    p1133::Solution2 s2;
    res = s2.largestUniqueNumber(nums);
    EXPECT_EQ(res, 2);
}
