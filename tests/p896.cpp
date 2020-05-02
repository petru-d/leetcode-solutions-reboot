#include "pch.h"

#include "../problems/p896.h"

TEST(p896, t0)
{
    p896::Solution s;
    std::vector<int> data = {1, 2, 2, 3};
    auto res = s.isMonotonic(data);
    EXPECT_EQ(true, res);
}

TEST(p896, t1)
{
    p896::Solution s;
    std::vector<int> data = {6, 5, 4, 4};
    auto res = s.isMonotonic(data);
    EXPECT_EQ(true, res);
}

TEST(p896, t2)
{
    p896::Solution s;
    std::vector<int> data = {1, 3, 2};
    auto res = s.isMonotonic(data);
    EXPECT_EQ(false, res);
}

TEST(p896, t3)
{
    p896::Solution s;
    std::vector<int> data = {1, 2, 4, 5};
    auto res = s.isMonotonic(data);
    EXPECT_EQ(true, res);
}

TEST(p896, t4)
{
    p896::Solution s;
    std::vector<int> data = {1, 1, 1};
    auto res = s.isMonotonic(data);
    EXPECT_EQ(true, res);
}
