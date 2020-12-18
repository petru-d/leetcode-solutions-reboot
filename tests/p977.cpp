#include "pch.h"

#include "../problems/p977.h"

TEST(p977, t0)
{
    p977::Solution s;

    std::vector<int> nums = {-4, -1, 0, 3, 10};
    auto res = s.sortedSquares(nums);

    std::vector<int> expected = {0, 1, 9, 16, 100};
    EXPECT_EQ(res, expected);
}
