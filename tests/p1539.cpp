#include "pch.h"

#include "../problems/p1539.h"

TEST(p1539, t0)
{
    p1539::Solution s;

    std::vector<int> arr = {2, 3, 4, 7, 11};
    
    auto res = s.findKthPositive(arr, 5);

    EXPECT_EQ(res, 9);
}

TEST(p1539, t1)
{
    p1539::Solution s;

    std::vector<int> arr = {1, 2, 3, 4};

    auto res = s.findKthPositive(arr, 2);

    EXPECT_EQ(res, 6);
}
