#include "pch.h"

#include "../problems/p137.h"

TEST(p137, t0)
{
    p137::Solution s;
    std::vector<int> nums = {1, 2, 3, 1, 2, 3, 1, 2, 3, 4};

    auto res = s.singleNumber(nums);

    EXPECT_EQ(res, 4);
}

TEST(p137, t1)
{
    p137::Solution s;
    std::vector<int> nums = {2, 2, 3, 2};

    auto res = s.singleNumber(nums);

    EXPECT_EQ(res, 3);
}

TEST(p137, t2)
{
    p137::Solution s;
    std::vector<int> nums = {0, 1, 0, 1, 0, 1, 99};

    auto res = s.singleNumber(nums);

    EXPECT_EQ(res, 99);
}

TEST(p137, t3)
{
    p137::Solution s;
    std::vector<int> nums = {0, -1, 0, -1, 0, -1, -99};

    auto res = s.singleNumber(nums);

    EXPECT_EQ(res, -99);
}
TEST(p137, t4)
{
    p137::Solution s;
    std::vector<int> nums = {43,          16,
                             45,          89,
                             45,          -2147483647 - 1,
                             45,          2147483646,
                             -2147483647, -2147483647 - 1,
                             43,          2147483647,
                             -2147483646, -2147483647 - 1,
                             89,          -2147483646,
                             89,          -2147483646,
                             -2147483647, 2147483646,
                             -2147483647, 16,
                             16,          2147483646,
                             43};

    auto res = s.singleNumber(nums);

    EXPECT_EQ(res, 2147483647);
}

TEST(p137, t5)
{
    p137::Solution s;
    std::vector<int> nums = {-401451, -177656,     -2147483646,     -473874,    -814645, -2147483646, -852036, -457533,
                             -401451, -473874,     -401451,         -216555,    -917279, -457533,     -852036, -457533,
                             -177656, -2147483646, -177656,         -917279,    -473874, -852036,     -917279, -216555,
                             -814645, 2147483645,  -2147483647 - 1, 2147483645, -814645, 2147483645,  -216555};

    auto res = s.singleNumber(nums);

    EXPECT_EQ(res, -2147483647 - 1);
}
