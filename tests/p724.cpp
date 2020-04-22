#include "pch.h"

#include "../problems/p724.h"

TEST(p724, t0)
{
    p724::Solution s;

    std::vector<int> data = {1, 7, 3, 6, 5, 6};

    int result = s.pivotIndex(data);

    EXPECT_EQ(result, 3);
}

TEST(p724, t1)
{
    p724::Solution s;

    std::vector<int> data = {1, 2, 3};

    int result = s.pivotIndex(data);

    EXPECT_EQ(result, -1);
}

TEST(p724, t2)
{
    p724::Solution s;

    std::vector<int> data = {-1, -1, -1, 0, 1, 1};

    int result = s.pivotIndex(data);

    EXPECT_EQ(result, 0);
}

TEST(p724, t3)
{
    p724::Solution s;

    std::vector<int> data = {1, 2, -3, 300};

    int result = s.pivotIndex(data);

    EXPECT_EQ(result, 3);
}
