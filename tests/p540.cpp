#include "pch.h"

#include "../problems/p540.h"

TEST(p540, t0)
{
    p540::Solution s;

    std::vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    auto res = s.singleNonDuplicate(nums);

    EXPECT_EQ(res, 2);
}

TEST(p540, t1)
{
    p540::Solution s;

    std::vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
    auto res = s.singleNonDuplicate(nums);

    EXPECT_EQ(res, 10);
}
