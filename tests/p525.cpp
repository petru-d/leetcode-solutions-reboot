#include "pch.h"

#include "../problems/p525.h"

TEST(p525, t0)
{
    p525::Solution s;
    std::vector<int> data = {0, 1};
    auto result = s.findMaxLength(data);
    EXPECT_EQ(result, 2);
}

TEST(p525, t1)
{
    p525::Solution s;
    std::vector<int> data = {0, 1, 0};
    auto result = s.findMaxLength(data);
    EXPECT_EQ(result, 2);
}

TEST(p525, t2)
{
    p525::Solution s;
    std::vector<int> data = {0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1};
    auto result = s.findMaxLength(data);
    EXPECT_EQ(result, 10);
}

TEST(p525, t3)
{
    p525::Solution s;
    std::vector<int> data = {0, 0, 0, 0};
    auto result = s.findMaxLength(data);
    EXPECT_EQ(result, 0);
}

TEST(p525, t4)
{
    p525::Solution s;
    std::vector<int> data = {0, 0, 1, 0, 0, 0, 1, 1};
    auto result = s.findMaxLength(data);
    EXPECT_EQ(result, 6);
}