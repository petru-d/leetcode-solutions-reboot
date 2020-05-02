#include "pch.h"

#include "../problems/p376.h"

TEST(p376, t0)
{

    std::vector<int> nums = {1, 7, 4, 9, 2, 5};
    p376::Solution s;
    auto res = s.wiggleMaxLength(nums);

    EXPECT_EQ(res, 6);
}

TEST(p376, t1)
{

    std::vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    p376::Solution s;
    auto res = s.wiggleMaxLength(nums);

    EXPECT_EQ(res, 7);
}

TEST(p376, t2)
{

    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    p376::Solution s;
    auto res = s.wiggleMaxLength(nums);

    EXPECT_EQ(res, 2);
}
