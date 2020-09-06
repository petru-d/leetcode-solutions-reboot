#include "pch.h"

#include "../problems/p952.h"

TEST(p952, t0)
{
    p952::Solution s;

    std::vector<int> A = {4, 6, 15, 35};
    auto res = s.largestComponentSize(A);

    EXPECT_EQ(res, 4);
}

TEST(p952, t1)
{
    p952::Solution s;

    std::vector<int> A = {20, 50, 9, 63};
    auto res = s.largestComponentSize(A);

    EXPECT_EQ(res, 2);
}

TEST(p952, t2)
{
    p952::Solution s;

    std::vector<int> A = {2, 3, 6, 7, 4, 12, 21, 39};
    auto res = s.largestComponentSize(A);

    EXPECT_EQ(res, 8);
}

TEST(p952, t3)
{
    p952::Solution s;

    std::vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto res = s.largestComponentSize(A);

    EXPECT_EQ(res, 6);
}