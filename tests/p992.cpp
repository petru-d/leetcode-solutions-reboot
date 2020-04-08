#include "pch.h"

#include "../problems/p992.h"

TEST(p992, T0)
{
    p992::Solution s;

    std::vector<int> data = {1, 2, 1, 2, 3};
    auto result = s.subarraysWithKDistinct(data, 2);

    EXPECT_EQ(result, 7);
}

TEST(p992, T1)
{
    p992::Solution s;

    std::vector<int> data = {1, 2, 1, 3, 4};
    auto result = s.subarraysWithKDistinct(data, 3);

    EXPECT_EQ(result, 3);
}