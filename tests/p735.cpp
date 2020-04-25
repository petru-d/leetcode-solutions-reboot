#include "pch.h"

#include "../problems/p735.h"

TEST(p735, t0)
{
    p735::Solution s;
    std::vector<int> data = {5, 10, -5};
    auto res = s.asteroidCollision(data);
    std::vector<int> expected = {5, 10};
    EXPECT_EQ(res, expected);
}

TEST(p735, t1)
{
    p735::Solution s;
    std::vector<int> data = {8, -8};
    auto res = s.asteroidCollision(data);
    std::vector<int> expected = {};
    EXPECT_EQ(res, expected);
}

TEST(p735, t2)
{
    p735::Solution s;
    std::vector<int> data = {10, 2, -5};
    auto res = s.asteroidCollision(data);
    std::vector<int> expected = {10};
    EXPECT_EQ(res, expected);
}

TEST(p735, t3)
{
    p735::Solution s;
    std::vector<int> data = {-2, -1, 1, 2};
    auto res = s.asteroidCollision(data);
    std::vector<int> expected = {-2, -1, 1, 2};
    EXPECT_EQ(res, expected);
}

TEST(p735, t4)
{
    p735::Solution s;
    std::vector<int> data = {-2, 2, 1, -2};
    auto res = s.asteroidCollision(data);
    std::vector<int> expected = {-2};
    EXPECT_EQ(res, expected);
}

TEST(p735, t5)
{
    p735::Solution s;
    std::vector<int> data = {1, -1, -2, -2};
    auto res = s.asteroidCollision(data);
    std::vector<int> expected = {-2, -2};
    EXPECT_EQ(res, expected);
}
