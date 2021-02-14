#include "pch.h"

#include "../problems/p1679.h"

TEST(p1679, t0)
{
    p1679::Solution s;

    std::vector<int> nums = {1, 2, 3, 4};
    auto res = s.maxOperations(nums, 5);

    EXPECT_EQ(res, 2);
}
