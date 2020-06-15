#include "pch.h"

#include "../problems/p368.h"

TEST(p368, t0)
{
    p368::Solution_graphs s;

    std::vector<int> nums = {1, 2, 4, 8};
    auto res = s.largestDivisibleSubset(nums);

    std::vector<int> exp = {1, 2, 4, 8};
    EXPECT_EQ(res, exp);
}

TEST(p368, t1)
{
    p368::Solution_graphs s;

    std::vector<int> nums = {1, 2, 3};
    auto res = s.largestDivisibleSubset(nums);

    std::vector<int> exp = {1, 2};
    EXPECT_EQ(res, exp);
}

TEST(p368, t2)
{
    p368::Solution_graphs s;

    std::vector<int> nums = {1, 2, 5, 10};
    auto res = s.largestDivisibleSubset(nums);

    std::vector<int> exp = {1, 2, 10};
    EXPECT_EQ(res, exp);
}

TEST(p368, t3)
{
    p368::Solution_graphs s;

    std::vector<int> nums = {2, 3, 4, 6, 8, 12, 24};
    auto res = s.largestDivisibleSubset(nums);

    std::vector<int> exp = {2, 4, 8, 24};
    EXPECT_EQ(res, exp);
}

TEST(p368, t4)
{
    p368::Solution s;

    std::vector<int> nums = {1, 2, 4, 8};
    auto res = s.largestDivisibleSubset(nums);

    std::vector<int> exp = {8, 4, 2, 1};
    EXPECT_EQ(res, exp);
}
