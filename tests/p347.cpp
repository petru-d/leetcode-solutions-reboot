#include "pch.h"

#include "../problems/p347.h"

TEST(p347, t0)
{
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};

    p347::Solution s;
    auto res = s.topKFrequent(nums, 2);

    std::vector<int> expected = {2, 1};

    EXPECT_EQ(expected, res);
}

TEST(p347, t1)
{
    std::vector<int> nums = {1};

    p347::Solution s;
    auto res = s.topKFrequent(nums, 1);

    std::vector<int> expected = {1};

    EXPECT_EQ(expected, res);
}

TEST(p347, t2)
{
    std::vector<int> nums = {3, 0, 1, 0};

    p347::Solution s;
    auto res = s.topKFrequent(nums, 1);

    std::vector<int> expected = {0};

    EXPECT_EQ(expected, res);
}
