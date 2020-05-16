#include "pch.h"

#include "../problems/p918.h"

TEST(p918, t0)
{
    p918::Solution s;

    std::vector<int> nums = {1, -2, 3, -2};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, 3);
}

TEST(p918, t1)
{
    p918::Solution s;

    std::vector<int> nums = {5, -3, 5};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, 10);
}

TEST(p918, t2)
{
    p918::Solution s;

    std::vector<int> nums = {3, -1, 2, -1};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, 4);
}

TEST(p918, t3)
{
    p918::Solution s;

    std::vector<int> nums = {3, -2, 2, -3};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, 3);
}

TEST(p918, t4)
{
    p918::Solution s;

    std::vector<int> nums = {-2, -3, -1};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, -1);
}

TEST(p918, t5)
{
    p918::Solution s;

    std::vector<int> nums = {5, 5, 0, -5, 3, -3, 2};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, 12);
}

TEST(p918, t6)
{
    p918::Solution s;

    std::vector<int> nums = {2, -2, 2, 7, 8, 0};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, 19);
}

TEST(p918, t7)
{
    p918::Solution s;

    std::vector<int> nums = {0, 5, 8, -9, 9, -7, 3, -2};
    auto res = s.maxSubarraySumCircular(nums);
    EXPECT_EQ(res, 16);
}
